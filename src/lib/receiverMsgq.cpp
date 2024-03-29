#include "MsgqCommon.hpp"

ReceiverMsgq::ReceiverMsgq(const std::string &mqName)
    : mqName_(mqName)
{
    struct mq_attr attr;
    attr.mq_maxmsg = 1;
    attr.mq_msgsize = bufSize_;
    mqd_ = mq_open(mqName_.c_str(), O_RDONLY | O_CREAT, 0666, &attr);
    if (mqd_ == -1)
    {
        throw std::runtime_error("mq_open():" + std::string(strerror(errno)));
    }
}

ReceiverMsgq::~ReceiverMsgq()
{
    mq_close(mqd_);
    mq_unlink(mqName_.c_str());
}

void ReceiverMsgq::receiveFile(std::string filePath)
{
    std::ofstream out(filePath, std::ios_base::out | std::ios_base::binary);
    std::vector<char> buf(bufSize_);
    int received_size = 0;
    do
    {
        received_size = mq_receive(mqd_, buf.data(), bufSize_, NULL);
        if (received_size == -1)
        {
            throw std::runtime_error("mq_receive():" + std::string(strerror(errno)));
        }
        out.write(buf.data(), received_size);
    } while (received_size > 0);

    out.close();
}