#include "argsParser.hpp"

ArgsParser::ArgsParser(int argc, char* argv[])
{
    int longindex;
        int ch;
        bool isFileProvided = -1;
        while ((ch = getopt_long(argc, argv, "hqpsf:", longopts, &longindex)) != -1)
        {
            switch (ch)
            {
            case 'f':
                fileName = optarg;	
                break;
            case 'p':
                method = ipcType::Pipe;
                isFileProvided = 0;
                break;
            case 's':
                method = ipcType::SharedMemory;
                break;
            case 'q':
                method = ipcType::Queue;
                break;
            case 'h':
                std::cout << "Usage: my_program [-p] for file transfer by named pipe" << std::endl;
                std::cout << "                  [-q] for file transfer by message queue (not implemented yet)" << std::endl;
                std::cout << "                  [-s] for file transfer by shared memory (not implemented yet)" << std::endl;
                std::cout << "                  [-f] for file to read/write" << std::endl;
                std::cout << "                  [-h] for this help command" << std::endl;
                std::cout << "                  Note: Please be careful about the file permissions" << std::endl;
                method = ipcType::OtherSituation;
                isFileProvided = 0;
                break;
            default:
                throw std::runtime_error("argsParser:Args from command line error");
            }
            if (isFileProvided == -1)
            throw std::runtime_error("argsParser:The file name has not been provided or error happens!");
            close(isFileProvided);
        }
                                              
}

struct option ArgsParser::longopts[] = {
    {"help", no_argument, NULL, 'h'},
    {"pipe", no_argument, NULL, 'p'},
    {"queue", no_argument, NULL, 'q'},
    {"shm", no_argument, NULL, 's'},
    {"file", required_argument, NULL, 'f'},
    {NULL, 0, NULL, 0}
};