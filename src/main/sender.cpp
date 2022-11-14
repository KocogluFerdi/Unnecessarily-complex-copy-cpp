#include "src/lib/pipeCommon.hpp"
#include "src/lib/argsParser.hpp"


int main(int argc, char **argv)
{
    try{
        ArgsParser argsParser(argc,argv);
        std::string fileName = argsParser.getFileName();
        ipcType method = argsParser.getMethod();
        switch (method)
        {
        case ipcType::Pipe:
        {
            std::cout << "File is used to send: " << fileName << std::endl;
            std::cout << "Pipe is used:" << std::endl;
            SenderPipe sender;
            sender.sendFile(fileName);
            break;
        }
        case ipcType::OtherSituation:
        {
return 0;
        }
        default:
        std::cout << "IPC Type is not valid"<< std::endl;
            return -1;
        }
    }
    catch(const std::exception &e){
        std::cerr << e.what() << '\n';
    }
    return 0;
}