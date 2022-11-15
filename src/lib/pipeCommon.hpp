#ifndef LIB_PIPE_COMMON_H
#define LIB_PIPE_COMMON_H
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <getopt.h>
#include <cstdio>
#include <vector>
#include <errno.h>
#include <string.h>

class CommonPipe
{
protected:
    std::string fifoPath_;
    size_t bufSize_ = 80;
public:
CommonPipe(){
        fifoPath_ = "/tmp/myfifo";
    }
   
};

class ReceiverPipe : public CommonPipe
{
public:
    ReceiverPipe():CommonPipe(){};
    ReceiverPipe(const std::string &fifoPath);
    ~ReceiverPipe();
    void receiveFile(std::string filePath);
};

class SenderPipe : public CommonPipe
{
public:
    SenderPipe():CommonPipe(){};
    SenderPipe(const std::string &fifoPath);
    ~SenderPipe();
    void sendFile(std::string filePath);
};





#endif