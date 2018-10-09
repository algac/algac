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
#ifndef ALGAC_BASE_STRING_H_
#define ALGAC_BASE_STRING_H_

#include <algorithm>
#include <sstream>  // stringstream
#include <string>
#include <vector>

namespace algac {

using std::string;        // from string
using std::stringstream;  // from sstream

using std::getline;    // from string
using std::to_string;  // from string

inline static string TrimLeft(string input) {
  input.erase(input.begin(),              // Erase from start
              std::find_if(               // Find 1st nonspace char
                  input.begin(),          //
                  input.end(),            //
                  [](int ch) {            //
                    return !isspace(ch);  //
                  })                      //
  );
  return input;
}

inline static string TrimRight(string input) {
  input.erase(std::find_if(               //
                  input.rbegin(),         //
                  input.rend(),           //
                  [](int ch) {            //
                    return !isspace(ch);  //
                  })                      //
                  .base(),                // Erase from tail
              input.end()                 // To end
  );
  return input;
}

inline static string Trim(string input) {  // TrimLeft + TrimRight
  return TrimLeft(TrimRight(input));
}

inline static std::vector<string> Split(const std::string &s,
                                        const std::string &delim,
                                        bool skip_blank_elem = true) noexcept {
  std::vector<std::string> elems;
  std::string item;
  if (delim.empty()) {
    elems.push_back(s);
    return elems;
  }
  std::string::const_iterator substart = s.begin(), subend;
  while (true) {
    subend = search(substart, s.end(), delim.begin(), delim.end());
    std::string temp(substart, subend);
    if (!skip_blank_elem || !temp.empty()) {
      elems.push_back(temp);
    }
    if (subend == s.end()) {
      break;
    }
    substart = subend + delim.size();
  }
  return elems;
}

inline static string ToLower(string input) {
  string out;
  for (const auto c : input) {
    out += std::tolower(c);
  }
  return out;
}

inline static string ToUpper(string input) {
  string out;
  for (const auto c : input) {
    out += std::toupper(c);
  }
  return out;
}

}  // namespace algac

#endif  // ALGAC_BASE_STRING_H_
