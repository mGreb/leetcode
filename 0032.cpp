/*
 * 32. Longest Valid Parentheses
 * Hard
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 * Example 1:
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * Example 2:
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * Example 3:
 * Input: s = ""
 * Output: 0
 * Constraints:
 * 0 <= s.length <= 3 * 104
 * s[i] is '(', or ')'.
 * */

#include <string>
#include <stack>

class Solution {
public:
  static size_t count(const std::string& s) {
    size_t cnt = 0;
    size_t max = 0;
    for (size_t i = 0; i < s.size(); ++i)
      if (s[i] == 'a') {
        ++cnt;
        max = std::max(cnt, max);
      } else
        cnt = 0;
    
    return max;
  }
  
  static size_t find_next(const std::string& s, size_t pos) {
    for (size_t i = pos + 1; i < s.size(); ++i) {
      if (s[i] == 'a')
        continue;
      if (s[i] == ')')
        return i;
      if (s[i] == '(')
        return pos;
    }
    return pos;
  }
  
  static int longestValidParentheses(std::string s) {
    bool no_more_left = false;
    while (!no_more_left) {
      no_more_left = true;
      for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
          const size_t res = find_next(s, i);
          if (res != i) {
            s[i] = s[res] = 'a';
            i = res;
            no_more_left = false;
          }
        }
      }
    }
    
    return count(s);
  }
};

int main() {
  const bool res0 = Solution::longestValidParentheses("(()())") == 6;
  const bool res1 = Solution::longestValidParentheses("(()") == 2;
  const bool res2 = Solution::longestValidParentheses(")()())") == 4;
  const bool res3 = Solution::longestValidParentheses("") == 0;
  const bool res4 = Solution::longestValidParentheses(")") == 0;
  const bool res5 = Solution::longestValidParentheses("(") == 0;
  const bool res6 = Solution::longestValidParentheses("()") == 2;
  const bool res7 = Solution::longestValidParentheses("()(()") == 2;
  return 0;
}
