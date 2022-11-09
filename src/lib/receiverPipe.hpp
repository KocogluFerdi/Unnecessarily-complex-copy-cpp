#ifndef LIB_RECEIVER_PIPE_H_
#define LIB_RECEIVER_PIPE_H_
#include <iostream>
#include <string>
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
#include <gtest/gtest_prod.h>
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

#endif