# Unnecessarily complex way to copy a file in C++

Target OS: Linux

Programs: Sender - Receiver

Goal: Transferring the files between two processes. "sender" program reads the file and send it to "receiver". Then, "receiver" gets the file and save it.

The file transfer happens via one of these three protocols:

PIPE, SHARED MEMORY and MESSAGE QUEUE

## Progress

- [x] argsParser Class Implementation
- [x] Sender Implementation
- [x] Receiver Implementation
- [x] Sender Pipe Implementation
- [x] Receiver Pipe Implementation
- [x] Sender SHM Implementation
- [x] Receiver SHM Implementation
- [x] Sender Message Queue Implementation
- [x] Receiver Message Queue Implementation

## How to

1. Run the "environment_setup.sh" to install the required tools.
2. Run the "build_and_test.sh" to build to binary files of "receiver" and "sender" and to test the program.
3. The test log can be accessed in "test.log" and the binary files can be accessed in "sender_and_receiver" folder.