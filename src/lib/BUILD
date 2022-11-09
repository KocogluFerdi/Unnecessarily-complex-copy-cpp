load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "argsParser",
    hdrs = ["argsParser.hpp"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "senderPipe",
    srcs = ["senderPipe.cpp"],
    hdrs = ["senderPipe.hpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "receiverPipe",
    srcs = ["receiverPipe.cpp"],
    hdrs = ["receiverPipe.hpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:public"],
)
