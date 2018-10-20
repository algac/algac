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
#ifndef ALGAC_BASE_VECTOR_H_
#define ALGAC_BASE_VECTOR_H_

#include <vector>

namespace algac {

using std::vector;

// template <typename T>
// using Matrix2d = vector<vector<T>>;

template <typename T>
vector<vector<T>> Vec2d(int row, int col) {
  vector<vector<T>> vec(row, vector<T>(col));
  // vec[row][col]
  return vec;
}

template <typename T>
vector<vector<T>> Vec2d(int row, int col, T value) {
  vector<vector<T>> vec(row, vector<T>(col, value));
  // vec[row][col]
  return vec;
}

}  // namespace algac

#endif  // ALGAC_BASE_VECTOR_H_
