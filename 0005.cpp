/* 5. Longest Palindromic Substring
 * Medium
 * Given a string s, return the longest palindromic substring in s.
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 * Constraints:
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * */

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <chrono>

class Solution {
public:
  static bool isPalindrome(const std::string& s, size_t begin, size_t end) {
    while (begin < end) {
      if (s[begin] != s[end]) {
        return false;
      }
      ++begin;
      --end;
    }
    return true;
  }
  static std::string longestPalindrome(const std::string& s) {
    size_t max_len = 0;
    size_t left = 0;
    size_t right = 0;
    for (size_t i = 0; i < s.size(); ++i)
      for (size_t j = s.size() - 1; j > i; --j)
        if (s[i] == s[j]) {
          if (isPalindrome(s, i, j)) {
            if (j - i + 1 > max_len) {
              max_len = j - i + 1;
              left = i;
              right = j;
            }
            j = i + 1;  // if palindrome found, no need to check inside it
          }
        }
    if (max_len <= 1)
      return {s[0]};
    else
      return s.substr(left, right - left + 1);
  }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::longestPalindrome("babad") == "bab");
  res.push_back(Solution::longestPalindrome("cbbd") == "bb");
  
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  res.push_back(Solution::longestPalindrome("abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "babababababababababababa") == "abababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababababababababababababa"
                                            "bababababababababababababababababababababababababababababababababababababab"
                                            "abababababababababababababababababababababababababababa");
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << " ms" << std::endl;
  
  begin = std::chrono::steady_clock::now();
  res.push_back(Solution::longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaa") == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  end = std::chrono::steady_clock::now();
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << " ms" << std::endl;
  
  return 0;
}
