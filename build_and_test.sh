#!/usr/bin/bash
#[ "$(whoami)" != "root" ] && exec sudo -- "$0" "$@"

DIR="sender_and_receiver"
if [ -d $DIR ] ; then
echo "sender_and_receiver directory exist. "
echo "Do you want to delete it? "
echo "Type yes or no"
    rm sender_and_receiver -r
    
fi

if [ -f "test.log" ] ; then
    echo "test.log exist."
    echo "Do you want to delete it?"
    echo "Type yes or no"
    rm test.log -r
   
fi

echo "Start building sender and receiver"
bazel build --cxxopt='-std=c++14' //src/main:sender
bazel build --cxxopt='-std=c++14' //src/main:receiver
echo "Finished building"
mkdir $DIR
cp ./bazel-bin/src/main/sender $DIR
cp ./bazel-bin/src/main/receiver $DIR
echo "Binary files are in sender_and_receiver directory now!"

bazel test //test:test
cp ./bazel-testlogs/test/test/test.log .
echo "Test log is in current directory!"
bazel clean
