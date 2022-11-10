#include <gtest/gtest.h>
#include "src/lib/pipeCommon.hpp"


#include <string>
#include <thread>


void createFile(std::string fileName, std::string fileSize){
    std::system(("truncate -s "+fileSize+" "+fileName).c_str());
}
void deleteFile(std::string fileName){
    std::system(("rm "+fileName).c_str());
}



class PipeTest1k : public testing::Test {
 protected:  
  void SetUp() override {
    createFile(sendFileName,sendFileSize);
  }

  void TearDown() override {
    deleteFile(sendFileName);
  }

  std::string sendFileName = "gTest1.txt";
  std::string sendFileSize = "1k";
  std::string receiveFileName = "gTEST1";

};

class PipeTest1m : public testing::Test {
 protected:  
  void SetUp() override {
    createFile(sendFileName,sendFileSize);
  }

  void TearDown() override {
    deleteFile(sendFileName);
  }

  std::string sendFileName = "gTest2.txt";
  std::string sendFileSize = "1m";
  std::string receiveFileName = "gTEST2";
};

class PipeTest10m : public testing::Test {
 protected:  
  void SetUp() override {
    createFile(sendFileName,sendFileSize);
  }

  void TearDown() override {
    deleteFile(sendFileName);
  }

  std::string sendFileName = "gTest3.txt";
  std::string sendFileSize = "10m";
  std::string receiveFileName = "gTEST3";
};

class PipeTest100m : public testing::Test {
 protected:  
  void SetUp() override {
    createFile(sendFileName,sendFileSize);
  }

  void TearDown() override {
    deleteFile(sendFileName);
  }

  std::string sendFileName = "gTest4.txt";
  std::string sendFileSize = "100m";
  std::string receiveFileName = "gTEST4";
};
TEST_F(PipeTest1k, Pipe)
{

    SenderPipe sender;
    ReceiverPipe receiver;

    auto senderSendFile = [&](){
        sender.sendFile(sendFileName);
    };

    auto receiverReceiveFile = [&](){
        receiver.receiveFile(receiveFileName);
    };

    std::thread s_thread(senderSendFile);
    std::thread r_thread(receiverReceiveFile);
    s_thread.join();
    r_thread.join();
    deleteFile(receiveFileName);
}

TEST_F(PipeTest1m, Pipe)
{

    SenderPipe sender;
    ReceiverPipe receiver;

    auto senderSendFile = [&](){
        sender.sendFile(sendFileName);
    };

    auto receiverReceiveFile = [&](){
        receiver.receiveFile(receiveFileName);
    };

    std::thread s_thread(senderSendFile);
    std::thread r_thread(receiverReceiveFile);
    s_thread.join();
    r_thread.join();
    deleteFile(receiveFileName);
}

TEST_F(PipeTest10m, Pipe)
{

    SenderPipe sender;
    ReceiverPipe receiver;

    auto senderSendFile = [&](){
        sender.sendFile(sendFileName);
    };

    auto receiverReceiveFile = [&](){
        receiver.receiveFile(receiveFileName);
    };

    std::thread s_thread(senderSendFile);
    std::thread r_thread(receiverReceiveFile);
    s_thread.join();
    r_thread.join();

    deleteFile(receiveFileName);
}

TEST_F(PipeTest100m, Pipe)
{

    SenderPipe sender;
    ReceiverPipe receiver;

    auto senderSendFile = [&](){
        sender.sendFile(sendFileName);
    };

    auto receiverReceiveFile = [&](){
        receiver.receiveFile(receiveFileName);
    };

    std::thread s_thread(senderSendFile);
    std::thread r_thread(receiverReceiveFile);
    s_thread.join();
    r_thread.join();

    deleteFile(receiveFileName);
}

