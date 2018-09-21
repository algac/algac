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
#ifndef ALGAC_BASE_BASE_H_
#define ALGAC_BASE_BASE_H_

#include <atomic>
#include <deque>
#include <iostream>
#include <queue>  // queue & priority_queue
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "algac/base/utils.h"

namespace algac {

typedef int64_t i64t;
typedef int32_t i32t;
typedef int16_t i16t;
typedef int8_t i8t;
typedef char i4t;

typedef uint64_t u64t;
typedef uint32_t u32t;
typedef uint16_t u16t;
typedef uint8_t u8t;
typedef unsigned char u4t;

typedef long double f128t;
typedef double f64t;
typedef float f32t;

using std::string;

template <typename T>
using atomic = std::atomic<T>;  // typedef std::atomic<T> as atomic<T>

using std::deque;
using std::priority_queue;
using std::queue;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::vector;

auto tf = std::boolalpha;
auto notf = std::noboolalpha;

}  // namespace algac

#endif  // ALGAC_BASE_BASE_H_
