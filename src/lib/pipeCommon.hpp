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

class ReceiverPipe
{
private:
    std::string fifoPath_;
    size_t bufSize_ = 80;

public:
    ReceiverPipe(const std::string &fifoPath = "/tmp/myfifo");
    ~ReceiverPipe();
    void receiveFile(std::string filePath);

};

class SenderPipe
{
private:
    std::string fifoPath_;
    size_t bufSize_ = 80;
public:
    SenderPipe(const std::string &fifoPath = "/tmp/myfifo");
    ~SenderPipe();
    void sendFile(std::string filePath);

};

#endif