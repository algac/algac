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
#include "algac/base/algorithm.h"

#include <atomic>
#include <deque>
#include <functional>  // function
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "algac/base/base.h"

#include "glog/logging.h"
#include "gtest/gtest.h"

namespace algac {
TEST(Algorithm, BSearch) {
  InitGoogleLogging();
  vector<int> vec{1, 2, 3, 4, 5, 6};
  int off = BSearch<int>(vec, 4, 0, vec.size());
  EXPECT_EQ(3, off);
  LOG(INFO) << "BSearch element does not exists: "
            << BSearch<int>(vec, 9, 0, vec.size());
}

TEST(Algorithm, Sort) {
  InitGoogleLogging();

  int step = 0;

  std::function<void(const vector<int>&)> PrintVector =
      [&step](const vector<int>& v) {
        string line;
        for (const auto& e : v) {
          // LOG(INFO) << "elem = " << e;
          line += std::to_string(e);
          line += " ";
        }
        LOG(INFO) << "Vector[" << (step++) << "] ( size = " << v.size()
                  << " ): " << line;
      };

  vector<int> vec{32, 71, 12, 45, 26, 80, 53, 33};  // 32 71 12 45 26 80 53 33

  EXPECT_EQ(32, vec[0]);
  EXPECT_EQ(71, vec[1]);
  EXPECT_EQ(12, vec[2]);
  EXPECT_EQ(45, vec[3]);
  EXPECT_EQ(26, vec[4]);
  EXPECT_EQ(80, vec[5]);
  EXPECT_EQ(53, vec[6]);
  EXPECT_EQ(33, vec[7]);

  PrintVector(vec);

  // using default comparison (operator <):
  sort(vec.begin(), vec.begin() + 4);  //(12 32 45 71)26 80 53 33

  EXPECT_EQ(12, vec[0]);
  EXPECT_EQ(32, vec[1]);
  EXPECT_EQ(45, vec[2]);
  EXPECT_EQ(71, vec[3]);
  EXPECT_EQ(26, vec[4]);
  EXPECT_EQ(80, vec[5]);
  EXPECT_EQ(53, vec[6]);
  EXPECT_EQ(33, vec[7]);

  PrintVector(vec);

  // using function as comp
  sort(vec.begin() + 5, vec.end(), [](int l, int r) -> bool {
    return (l / 10 - l % 10) < (r / 10 - r % 10);
  });  // 12 32 45 71 26 { 33 53 80 }

  EXPECT_EQ(12, vec[0]);
  EXPECT_EQ(32, vec[1]);
  EXPECT_EQ(45, vec[2]);
  EXPECT_EQ(71, vec[3]);
  EXPECT_EQ(26, vec[4]);
  EXPECT_EQ(33, vec[5]);
  EXPECT_EQ(53, vec[6]);
  EXPECT_EQ(80, vec[7]);

  PrintVector(vec);
}
}  // namespace algac
