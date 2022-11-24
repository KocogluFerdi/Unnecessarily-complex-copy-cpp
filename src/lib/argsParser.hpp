#ifndef LIB_ARGS_PARSER_H_
#define LIB_ARGS_PARSER_H_
#include <iostream>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
enum class ipcType
{
    Pipe,
    Queue,
    SharedMemory,
    OtherSituation
};

class ArgsParser
{
private:
    std::string fileName;
    ipcType method;
    static struct option longopts[];

public:
    ArgsParser(int argc, char *argv[]);
    ~ArgsParser() {}
    std::string getFileName() const
    {
        return fileName;
    };
    ipcType getMethod() const
    {
        return method;
    };
};

#endif