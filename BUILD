cc_binary(
    name = "hello",
    srcs = [
      "main.cc",
    ],
    deps = [
        ":algac",
    ],
    visibility = [
      "//visibility:public",
    ],
)


cc_library(
    name = "algac",
    srcs = glob(
        [
            "algac/**/*.c",
            "algac/**/*.cc",
        ],
        exclude = [
            "algac/**/*_test.cc",
        ],
    ),
    hdrs = glob(
        [
            "algac/**/*.h",
        ],
        exclude = [
            "algac/**/*_test.h",
        ],
    ),
    deps = [
        "//external:glog",
        "@com_github_argcv_argcv//argcv/cxx:str",
    ],
)

cc_test(
    name = "algac_test",
    srcs = glob([
        "algac/**/*_test.cc",
        "algac/**/*_test.h",
    ]),
    deps = [
        "//external:glog",
        "//external:gtest_main",
        ":algac",
    ],
)