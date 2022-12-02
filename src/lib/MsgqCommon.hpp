#ifndef LIB_MSGQ_COMMON_H_
#define LIB_MSGQ_COMMON_H_
#include <string>
#include <mqueue.h>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <getopt.h>
#include <cstdio>
#include <string.h>
#include <errno.h>
#include <vector>
#include <cstring>

class SenderMsgq
{
private:
    std::string mqName_;
    mqd_t mqd_;
    size_t bufSize_ = 80;

public:
    SenderMsgq(const std::string &mqName = "/mqExample");
    ~SenderMsgq();
    void sendFile(std::string filePath);
};

class ReceiverMsgq
{
private:
    std::string mqName_;
    mqd_t mqd_;
    size_t bufSize_ = 80;

public:
    ReceiverMsgq(const std::string &mqName = "/mqExample");
    ~ReceiverMsgq();
    void receiveFile(std::string filePath);
};

#endif
