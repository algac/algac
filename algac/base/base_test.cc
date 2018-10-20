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
#include "algac/base/base.h"

#include <algorithm>
#include <atomic>
#include <deque>
#include <functional>  // function
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "glog/logging.h"
#include "gtest/gtest.h"

namespace algac {
TEST(Base, Basic) {
  InitGoogleLogging();
  EXPECT_EQ(8, sizeof(i64t));
  EXPECT_EQ(4, sizeof(i32t));
  EXPECT_EQ(2, sizeof(i16t));
  EXPECT_EQ(1, sizeof(i8t));
  EXPECT_EQ(1, sizeof(i4t));

  LOG(INFO) << "sizof(i64t) = " << sizeof(i64t);
  LOG(INFO) << "sizof(i32t) = " << sizeof(i32t);
  LOG(INFO) << "sizof(i16t) = " << sizeof(i16t);
  LOG(INFO) << "sizof(i8t) = " << sizeof(i8t);
  LOG(INFO) << "sizof(i4t) = " << sizeof(i4t);

  EXPECT_EQ(8, sizeof(u64t));
  EXPECT_EQ(4, sizeof(u32t));
  EXPECT_EQ(2, sizeof(u16t));
  EXPECT_EQ(1, sizeof(u8t));
  EXPECT_EQ(1, sizeof(u4t));

  LOG(INFO) << "sizof(u64t) = " << sizeof(u64t);
  LOG(INFO) << "sizof(u32t) = " << sizeof(u32t);
  LOG(INFO) << "sizof(u16t) = " << sizeof(u16t);
  LOG(INFO) << "sizof(u8t) = " << sizeof(u8t);
  LOG(INFO) << "sizof(u4t) = " << sizeof(u4t);

  EXPECT_EQ(16, sizeof(f128t));
  EXPECT_EQ(8, sizeof(f64t));
  EXPECT_EQ(4, sizeof(f32t));

  LOG(INFO) << "sizof(f128t) = " << sizeof(f128t);
  LOG(INFO) << "sizof(f64t) = " << sizeof(f64t);
  LOG(INFO) << "sizof(f32t) = " << sizeof(f32t);

  string s("123");
  EXPECT_EQ(3, s.size());

  LOG(INFO) << "s = " << s;
  LOG(INFO) << "s.size() = " << s.size();
}

template <typename T>
void PrintPqStack(T q) {
  string line;
  while (!q.empty()) {
    line += std::to_string(q.top());
    line += " ";
    q.pop();
  }
  LOG(INFO) << "PqStack ( size = " << q.size() << " ): " << line;
}

TEST(Base, PriorityQueue) {
  InitGoogleLogging();

  // int: element type
  priority_queue<int> q;

  for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) q.push(n);

  PrintPqStack(q);

  // int, T : element type
  // vector<int>, Container: in default is vector<T>
  // std::greater<int> Compare: in default is std::less<typename
  // Container::value_type> implemented as :
  //     constexpr bool operator()(const T &lhs, const T &rhs) const {
  //         return lhs < rhs;
  //     }
  // for std::greater<> : return lhs > rhs;
  // or std::less
  priority_queue<int, vector<int>, std::greater<int>> q2;

  for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) q2.push(n);

  PrintPqStack(q2);

  // Using lambda to compare elements.
  std::function<bool(const int&, const int&)> cmp =
      [](const int& l, const int& r) -> bool { return l % 10 < r % 10; };
  // type, container, compare,
  priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);

  for (int n : {14, 24, 33, 43, 52, 62, 71, 81, 91, 101, 116, 127, 137, 148})
    q3.push(n);

  PrintPqStack(q3);
}

TEST(Base, Queue) {
  InitGoogleLogging();
  deque<int> dq{1, 2, 3};
  queue<int> q(dq);

  LOG(INFO) << "q.empty() = " << q.empty();
  LOG(INFO) << "q.size() = " << q.size();
  LOG(INFO) << "q.front() = " << q.front();
  LOG(INFO) << "q.back() = " << q.back();

  q.emplace(4);
  q.push(5);

  string line;
  while (!q.empty()) {
    line += std::to_string(q.front());
    line += " ";
    q.pop();
  }
  LOG(INFO) << "Queue ( size = " << q.size() << " ): " << line;
}

TEST(Base, Stack) {
  InitGoogleLogging();
  stack<int> s({1, 2, 3});

  LOG(INFO) << "s.empty() = " << s.empty();
  LOG(INFO) << "s.size() = " << s.size();
  LOG(INFO) << "s.top() = " << s.top();

  s.emplace(4);
  s.push(5);

  PrintPqStack(s);
}

TEST(Base, UnorderedMap) {
  InitGoogleLogging();
  unordered_map<string, int> m{
      {"alice", 100},
      {"bob", 100},
  };
  m["alice"]++;
  m["bob"]--;
  m["charlie"]++;
  m["dave"] = 10;
  for (const auto& e : m) {
    LOG(INFO) << "m[\"" << e.first << "\"] = " << e.second;
  }
  LOG(INFO) << "found alice = " << tf << (m.find("alice") != m.end());
  LOG(INFO) << "got dave = " << (m.find("dave")->second);
  LOG(INFO) << "found eve = " << tf << (m.find("eve") != m.end());
}

TEST(Base, UnorderedSet) {
  InitGoogleLogging();
  unordered_set<string> s{
      "alice",
      "bob",
  };
  s.insert("charlie");
  for (const auto& e : s) {
    LOG(INFO) << "elem = " << e;
  }
  LOG(INFO) << "found alice = " << tf << (s.find("alice") != s.end());
  LOG(INFO) << "found charlie = " << tf << (s.find("charlie") != s.end());
  LOG(INFO) << "found dave = " << tf << (s.find("dave") != s.end());
}

TEST(Base, Vector) {
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

  vector<int> v{1, 2, 3};

  LOG(INFO) << "v.empty() = " << v.empty();
  LOG(INFO) << "v.size() = " << v.size();
  LOG(INFO) << "v.front() = " << v.front();
  LOG(INFO) << "v.back() = " << v.back();

  PrintVector(v);
  v.emplace(v.begin(), 4);
  PrintVector(v);
  v.insert(v.end(), 5);
  PrintVector(v);
  v.push_back(6);
  PrintVector(v);
  v.assign(5, 9);
  PrintVector(v);
  for (int i = 0; i < 5; i++) {
    v[i] = i;
  }
  PrintVector(v);
  v.erase(v.begin() + 2);
  PrintVector(v);

  int v2di = 2;
  int v2dj = 3;
  vector<vector<int>> v2d(v2di, vector<int>(v2dj));

  for (int i = 0; i < v2di; i++) {
    for (int j = 0; j < v2dj; j++) {
      v2d[i][j] = i * 10 + j;
    }
  }

  for (int i = 0; i < v2di; i++) {
    for (int j = 0; j < v2dj; j++) {
      v2d[i][j] = i * 10 + j;
      LOG(INFO) << "v2d[" << i << "][" << j << "] = " << v2d[i][j];
    }
  }
}

}  // namespace algac
