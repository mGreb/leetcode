/*
 * 3. Longest Substring Without Repeating Characters
 * Given a string s, find the length of the longest substring without repeating characters.
 * */

#include <string>
#include <array>
#include <vector>

class Solution {
public:
    static int lengthOfLongestSubstring(std::string s) {
        const size_t n = s.size();
        if (n < 2)
            return n;

        std::array<int, 128> dict;
        std::fill(dict.begin(), dict.end(), -1);
        size_t max_len = 0, cur_len = 0;
        int begin = 0;

        for (size_t i = 0; i < n; ++i) {
            
            const char l = s[i];
            bool broken_sequence = false;
            
            if (dict[l] > -1) {  // if symbol occured previously
                auto& pos = dict[l];
                if (pos >= begin) {  // if symbol belongs to current subsequence
                    broken_sequence = true;
                    begin = pos + 1;
                    max_len = std::max(max_len, cur_len);
                    cur_len = i - pos;
                    pos = i;
                }
            }

            if (!broken_sequence) {
                dict[l] = i;
                ++cur_len;
            }
        }

        return std::max(max_len, cur_len);
    }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::lengthOfLongestSubstring("tmmzuxt") == 5);
  res.push_back(Solution::lengthOfLongestSubstring("abcabc") == 3);
  res.push_back(Solution::lengthOfLongestSubstring("") == 0);
  res.push_back(Solution::lengthOfLongestSubstring("a") == 1);
  res.push_back(Solution::lengthOfLongestSubstring("abc") == 3);
  res.push_back(Solution::lengthOfLongestSubstring("bbbbbbbbb") == 1);
  res.push_back(Solution::lengthOfLongestSubstring("pwwkew") == 3);
  res.push_back(Solution::lengthOfLongestSubstring("abcabcbb") == 3);
  return 0;
}
