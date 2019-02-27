workspace(name = "algac")

load("//tools:argcv_repo.bzl", "argcv_repo")

argcv_repo(name = "com_github_argcv_argcv")

load("@com_github_argcv_argcv//tools:version.bzl", "check_version")

check_version("0.17.0")

load("@com_github_argcv_argcv//argcv:argcv.bzl", "ws_argcv")
ws_argcv("com_github_argcv_argcv")

