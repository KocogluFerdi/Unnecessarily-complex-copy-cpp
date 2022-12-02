cc_test(
  name = "test",
  size = "small",
  srcs = ["tests.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//src/lib:senderPipe",
    "//src/lib:receiverPipe",
    "//src/lib:senderShmem",
    "//src/lib:receiverShmem",
    "//src/lib:argsParser",

  ],
  linkopts = ["-lrt","-lpthread"],
)

