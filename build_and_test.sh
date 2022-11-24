#!/usr/bin/bash
#[ "$(whoami)" != "root" ] && exec sudo -- "$0" "$@"

DIR="sender_and_receiver"
if [ -d $DIR ] ; then
    rm sender_and_receiver -r -f
fi

if [ -f "test.log" ] ; then
    rm test.log -r -f
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