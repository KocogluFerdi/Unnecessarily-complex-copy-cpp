#include "src/lib/pipeCommon.hpp"
#include "src/lib/argsParser.hpp"


int main(int argc, char **argv)
{
    try{
        ArgsParser argsParser(argc,argv);
        std::string fileName = argsParser.getFileName();
        ipcType method = argsParser.getMethod();
        std::cout << "File is used to send:" << fileName << std::endl;
        switch (method)
        {
        case ipcType::Pipe:
        {
            std::cout << "Pipe is used:" << std::endl;
            SenderPipe sender;
            sender.sendFile(fileName);
            break;
        } 
        case ipcType::OtherSituation:
            return -1;
        default:
            return -1;
        }
    }
    catch(const std::exception &e){
        std::rethrow_exception(std::current_exception());
    }
    return 0;
}