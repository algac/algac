/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Yu Jing <yu@argcv.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 **/
#include "algac/base/utils.h"

#include <mutex>  // NOLINT(build/c++11)  std::once_flag

#include "glog/logging.h"

namespace algac {

static std::once_flag glog_init;

void InitGoogleLogging() {
  std::call_once(glog_init, []() {
    google::InitGoogleLogging("algac");

    // log_dir (string, default="")
    // If specified, logfiles are written into this directory instead of the
    // default logging directory.
    FLAGS_log_dir = "";

    // logtostderr (bool, default=false)
    // Log messages to stderr instead of logfiles.
    // Note:
    // you can set binary flags to true by specifying 1, true, or yes (case
    // insensitive). Also, you can set binary flags to false by specifying 0,
    // false, or no (again, case insensitive).
    FLAGS_logtostderr = true;

    // stderrthreshold (int, default=2, which is ERROR)
    // Copy log messages at or above this level to stderr in addition to
    // logfiles. The numbers of severity levels INFO, WARNING, ERROR, and FATAL
    // are 0, 1, 2, and 3, respectively.
    FLAGS_stderrthreshold = 2;

    // minloglevel (int, default=0, which is INFO)
    // Log messages at or above this level. Again, the numbers of severity
    // levels INFO, WARNING, ERROR, and FATAL are 0, 1, 2, and 3, respectively.
    FLAGS_minloglevel = 0;

    // Set color messages logged to stderr (if supported by terminal).
    FLAGS_colorlogtostderr = true;

    FLAGS_log_prefix = true;

    FLAGS_stop_logging_if_full_disk = true;
  });
}

}  // namespace algac
