workspace(name = "hello_gl")

load("//tools:argcv_repo.bzl", "argcv_repo")

argcv_repo(name = "com_github_argcv_argcv")

load("@com_github_argcv_argcv//tools:version.bzl", "check_version")

check_version("0.4.3")

load("@com_github_argcv_argcv//tools:argcv_deps.bzl", "argcv_deps")
argcv_deps("com_github_argcv_argcv")

