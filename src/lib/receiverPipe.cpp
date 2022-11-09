#include "receiverPipe.hpp"

ReceiverPipe::ReceiverPipe(const std::string &fifoPath)
:fifoPath_(fifoPath)
{
    if(mkfifo(fifoPath_.c_str(), 0666)!=0 && errno!=EEXIST){
        throw std::runtime_error("mkfifo():"+std::string(strerror(errno)));
    }
}

ReceiverPipe::~ReceiverPipe()
{
}

void ReceiverPipe::receiveFile(std::string filePath)
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
