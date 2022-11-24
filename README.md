# Unnecessarily complex way to copy a file in C++

Target OS: Linux

Programs: Sender - Receiver

Goal: Transferring the files between two processes. "sender" program reads the file and send it to "receiver". Then, "receiver" gets the file and save it.

The file transfer happens via one of these three protocols:

PIPE, MESSAGE QUEUE, and SHARED MEMORY

## Progress

- [x] argsParser Class Implementation
- [x] Sender Implementation
- [x] Receiver Implementation
- [x] Sender Pipe Implementation
- [x] Receiver Pipe Implementation
- [-] Receiver Message Queue Implementation
- [-] Sender Message Queue Implementation
- [-] Sender SHM Implementation
- [-] Receiver SHM Implementation

## How to

1. Run the "environment_setup.sh" to install the required tools.
2. Run the "build_and_test.sh" to build to binary files of "receiver" and "sender" and to test the program.
3. The test log can be accessed in "test.log" and the binary files can be accessed in "sender_and_receiver" folder.
