#include "src/lib/pipeCommon.hpp"
#include "src/lib/argsParser.hpp"

int main(int argc, char *argv[])
{
    try
    {
        ArgsParser argsParser(argc, argv);
        switch (argsParser.getMethod())
        {
        case ipcType::Pipe:
        {
            std::cout << "File is used to receive: " << argsParser.getFileName() << std::endl;
            std::cout << "Pipe is used" << std::endl;
            ReceiverPipe receiver;
            receiver.receiveFile(argsParser.getFileName());
            break;
        }
        case ipcType::OtherSituation:
        {
            return 0;
        }
        default:
        {
            std::cout << "IPC Type is not valid" << std::endl;
        }
        return -1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return -1;
}