#include "src/lib/pipeCommon.hpp"
#include "src/lib/argsParser.hpp"
#include "src/lib/shmemCommon.hpp"
#include "src/lib/MsgqCommon.hpp"

int main(int argc, char *argv[])
{
    try
    {
        ArgsParser argsParser(argc, argv);
        ipcType method = argsParser.getMethod();
        switch (method)
        {
        case ipcType::Pipe:
        {
            std::cout << "File is used to send: " << argsParser.getFileName() << std::endl;
            std::cout << "Pipe is used" << std::endl;
            SenderPipe sender;
            sender.sendFile(argsParser.getFileName());
            break;
        }
        case ipcType::SharedMemory:
        {
            std::cout << "Shared Memory Is Used: " << std::endl;
            SenderShmem sender;
            sender.init();
            sender.sendFile(argsParser.getFileName());
            break;
        }
          case ipcType::Queue:
        {
            std::cout << "Message Queue is used: " << std::endl;
            SenderMsgq sender;
            sender.sendFile(argsParser.getFileName());
            break;
        }
        case ipcType::OtherSituation:
        {
            return 0;
        }
        default:
            std::cout << "IPC Type is not valid" << std::endl;
            return -1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return -1;
}