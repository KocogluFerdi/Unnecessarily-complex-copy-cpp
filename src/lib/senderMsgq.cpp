#include "MsgqCommon.hpp"

SenderMsgq::SenderMsgq(const std::string &mqName)
    : mqName_(mqName)
{
    struct mq_attr attr;
    attr.mq_maxmsg = 1;
    attr.mq_msgsize = bufSize_;
    mqd_ = mq_open(mqName_.c_str(), O_WRONLY | O_CREAT, 0666, &attr);
    if (mqd_ == -1)
    {
        throw std::runtime_error("mq_open():" + std::string(strerror(errno)));
    }
}

SenderMsgq::~SenderMsgq()
{
    mq_close(mqd_);
    mq_unlink(mqName_.c_str());
}
void SenderMsgq::sendFile(std::string filePath)
{
    std::ifstream in(filePath, std::ios_base::in | std::ios_base::binary);
    std::vector<char> buf(bufSize_);

    do
    {
        in.read(buf.data(), bufSize_);
        if (mq_send(mqd_, buf.data(), in.gcount(), 0) != 0)
        {
            throw std::runtime_error("mq_send():" + std::string(strerror(errno)));
        }
    } while (in.gcount() > 0);
    in.close();
}