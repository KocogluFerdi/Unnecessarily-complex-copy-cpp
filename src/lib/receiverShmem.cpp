#include "shmemCommon.hpp"

ReceiverShmem::ReceiverShmem(const std::string &shmPath, const std::string &semProdName, const std::string &semConsName)
    : shmPath(shmPath), semProdName(semProdName), semConsName(semConsName)
{
}

void ReceiverShmem::init()
{
    semHandleProd = sem_open(semProdName.c_str(), O_RDWR);
    while (semHandleProd == SEM_FAILED)
    {
        std::cout << "Waiting for the sender to run..." << std::endl;
        sleep(2);
        semHandleProd = sem_open(semProdName.c_str(), O_RDWR);
    }

    semHandleCons = sem_open(semConsName.c_str(), O_RDWR);
    if (semHandleCons == SEM_FAILED)
    {
        throw std::runtime_error("sem_open() for consumer:" + std::string(strerror(errno)));
    }

    shmfd = shm_open(shmPath.c_str(), O_RDWR | O_CREAT, 0666);
    if (shmfd == -1)
    {
        throw std::runtime_error("shm_open():" + std::string(strerror(errno)));
    }
    memptr = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (memptr == (void *)-1)
    {
        throw std::runtime_error("mmap():" + std::string(strerror(errno)));
    }
    close(shmfd);
    shm_ctrl = reinterpret_cast<Shmem_control *>(static_cast<char *>(memptr) + BUF_SIZE);
}

void ReceiverShmem::receiveFile(std::string filePath)
{
    std::ofstream out(filePath, std::ios_base::out | std::ios_base::binary);
    std::vector<char> buf(BUF_SIZE);
    size_t receive_size = 0;
    do
    {
        sem_wait(semHandleProd);
        receive_size = shm_ctrl->bytes_send;
        out.write(static_cast<char *>(memptr), receive_size);
        sem_post(semHandleCons);
    } while (receive_size > 0);

    out.close();
}

ReceiverShmem::~ReceiverShmem()
{
    munmap(memptr, BUF_SIZE);
    sem_close(semHandleCons);
    sem_close(semHandleProd);
    shm_unlink(shmPath.c_str());
}