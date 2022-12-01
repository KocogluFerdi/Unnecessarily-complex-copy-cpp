#include "shmemCommon.hpp"

SenderShmem::SenderShmem(const std::string &shmPath, const std::string &semProdName, const std::string &semConsName)
    : shmPath(shmPath), semProdName(semProdName), semConsName(semConsName)
{
}

void SenderShmem::init()
{
    sem_unlink(semProdName.c_str());
    sem_unlink(semConsName.c_str());

    semHandleCons = sem_open(semConsName.c_str(), O_RDWR | O_CREAT, 0666, 1);
    if (semHandleCons == SEM_FAILED)
    {
        throw std::runtime_error("sem_open() for consumer:" + std::string(strerror(errno)));
    }

    semHandleProd = sem_open(semProdName.c_str(), O_RDWR | O_CREAT, 0666, 0);
    if (semHandleProd == SEM_FAILED)
    {
        throw std::runtime_error("sem_open() for producer:" + std::string(strerror(errno)));
    }

    shmfd = shm_open(shmPath.c_str(), O_RDWR | O_CREAT, 0666);
    if (shmfd == -1)
    {
        throw std::runtime_error("shm_open():" + std::string(strerror(errno)));
    }
    if (ftruncate(shmfd, BUF_SIZE + sizeof(Shmem_control)) != 0)
    {
        throw std::runtime_error("ftruncate():" + std::string(strerror(errno)));
    }

    memptr = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (memptr == (void *)-1)
    {
        throw std::runtime_error("mmap():" + std::string(strerror(errno)));
    }
    close(shmfd);
    shm_ctrl = reinterpret_cast<Shmem_control *>(static_cast<char *>(memptr) + BUF_SIZE);
}

void SenderShmem::sendFile(std::string filePath)
{
    std::ifstream in(filePath, std::ios_base::in | std::ios_base::binary);
    if (!in)
    {
        std::cout << "ERROR" << std::endl;
    }
    else
    {
        std::cout << "FILE OPEN" << std::endl;
    }
    std::vector<char> buf(BUF_SIZE);

    do
    {
        sem_wait(semHandleCons);
        in.read(static_cast<char *>(memptr), buf.size());
        shm_ctrl->bytes_send = in.gcount();
        sem_post(semHandleProd);
    } while (in.gcount() > 0);

    in.close();
}

SenderShmem::~SenderShmem()
{
    munmap(memptr, BUF_SIZE);
    sem_close(semHandleCons);
    sem_close(semHandleProd);
    sem_unlink(semProdName.c_str());
    sem_unlink(semConsName.c_str());
    shm_unlink(shmPath.c_str());
}