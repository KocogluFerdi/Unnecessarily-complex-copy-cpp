load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


cc_binary(
    name = "sender",
    srcs = ["sender.cpp"],
    deps = [
        "//src/lib:senderPipe",
        "//src/lib:senderShmem",
        "//src/lib:senderMsgq",
        "//src/lib:argsParser"
    ],
    visibility = ["//visibility:public"],
    linkopts= ["-lrt","-pthread"],

)

cc_binary(
    name = "receiver",
    srcs = ["receiver.cpp"],
    deps = [
        "//src/lib:receiverPipe",
        "//src/lib:receiverShmem",
        "//src/lib:receiverMsgq",
        "//src/lib:argsParser",
    ],
    visibility = ["//visibility:public"],
    linkopts= ["-lrt","-pthread"],
)
