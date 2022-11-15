#include "pipeCommon.hpp"

ReceiverPipe::ReceiverPipe(const std::string &fifoPath)
{
    fifoPath_ = fifoPath;
if(mkfifo(fifoPath_.c_str(), 0666) !=0)
{
    if(errno != EEXIST) 
    {
        std::cout << "Error mkfifo(): ";  
        throw std::runtime_error("mkfifo():"+std::string(strerror(errno)));
    } 
    else 
    {
        std::cout << "FIFO already created" << std::endl;
        }
}
}

void ReceiverPipe::receiveFile(const std::string filePath)
{
    std::ifstream in;
    std::ofstream out;
    std::vector<char> buf(bufSize_);

    std::ios_base::iostate exceptionMaskIn = in.exceptions() | std::ios::failbit;
    in.exceptions(exceptionMaskIn);
    std::ios_base::iostate exceptionMaskOut = out.exceptions() | std::ios::failbit;
    out.exceptions(exceptionMaskOut);

    try
    {
        in.open(fifoPath_, std::ios_base::in | std::ios_base::binary);
        out.open(filePath, std::ios_base::out | std::ios_base::binary);

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
