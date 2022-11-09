#include "src/lib/receiverPipe.hpp"
#include "src/lib/argsParser.hpp"

int main(int argc, char **argv)
{
    try{
        ArgsParser argsParser(argc,argv);
        std::string fileName = argsParser.getFileName();
        std::cout << "File is used to receive:" << fileName << std::endl;
        switch (argsParser.getMethod())
        {
        case ipcType::Pipe:
        {
            std::cout << "Pipe is used:" << std::endl;
            ReceiverPipe receiver;
            receiver.receiveFile(fileName);
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
