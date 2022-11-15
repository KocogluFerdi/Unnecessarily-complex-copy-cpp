#include "src/lib/pipeCommon.hpp"
#include "src/lib/argsParser.hpp"

int main(int argc, char* argv[])
{
    try{
        ArgsParser argsParser(argc,argv);
        std::string fileName = argsParser.getFileName();
        switch (argsParser.getMethod())
        {
        case ipcType::Pipe:
        {
            std::cout << "File is used to receive: " << fileName << std::endl;
            std::cout << "Pipe is used:" << std::endl;
            ReceiverPipe receiver;
            receiver.receiveFile(fileName);
            break;
        }
        case ipcType::OtherSituation:
        {
    return 0;
        }
        default:
        std::cout << "IPC Type is not valid"<< std::endl ;
            return -1;
        
        }
    }
    catch(const std::exception &e){
        std::cerr << e.what() << '\n';
    }
    return -1;
}
