#include "pipeCommon.hpp"

ReceiverPipe::ReceiverPipe(const std::string &fifoPath)
:fifoPath_(fifoPath)
{
if(mkfifo(fifoPath_.c_str(), 0666) !=0)
{
    if(errno != EEXIST) 
    {
        std::cout << "Error mkfifo(): ";  
        throw std::runtime_error("mkfifo():"+std::string(strerror(errno)));
        exit(EXIT_FAILURE);
    } 
    else 
    {
        std::cout << "FIFO already created" << std::endl;
        }
}
}

void ReceiverPipe::receiveFile(std::string filePath)
{
    try
    {
        std::ifstream in(fifoPath_, std::ios_base::in | std::ios_base::binary);
        std::ofstream out(filePath, std::ios_base::out | std::ios_base::binary);
        std::vector<char> buf(bufSize_);

        do
        {
            in.read(buf.data(), buf.size());
            out.write(buf.data(), in.gcount());
        } while (in.gcount()>0);

        in.close();
        out.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}
   
   ReceiverPipe::~ReceiverPipe()
{
    remove(fifoPath_.c_str());
}
