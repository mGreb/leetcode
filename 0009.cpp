/*
 * 9. Palindrome Number
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward.
 * For example, 121 is a palindrome while 123 is not.
 * */

#include <vector>

class Solution {
public:
  static bool isPalindrome(const std::vector<int>& x) {
    for (size_t i = 0; i < x.size() / 2; i++) {
        if (x[i] != x[x.size() - 1 - i])
          return false;
     }
    return true;
  }

  static std::vector<int> vecInt(int x) {
    std::vector<int> v;
    do {
      const int y = x % 10;
      v.push_back(y);
      x = x / 10;
    } while (x != 0);
    return v;
  }

  static bool isPalindrome(int x) {
    if (x < 0)
      return false;
    return isPalindrome(vecInt(x));
  }

};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::vecInt(5320) == std::vector<int> {0, 2, 3, 5});
  res.push_back(Solution::vecInt(202) == std::vector<int> {2, 0, 2});
  res.push_back(Solution::vecInt(0) == std::vector<int> {0});
  res.push_back(Solution::vecInt(9) == std::vector<int> {9});
  
  res.push_back(Solution::isPalindrome({1, 2, 1}) == true);
  res.push_back(Solution::isPalindrome({1, 2, 2, 1}) == true);
  res.push_back(Solution::isPalindrome({1, 1, 0, 1}) == false);
  res.push_back(Solution::isPalindrome({1, 0}) == false);
  res.push_back(Solution::isPalindrome({1}) == true);
  
  res.push_back(Solution::isPalindrome(121) == true);
  res.push_back(Solution::isPalindrome(-1) == false);
  res.push_back(Solution::isPalindrome(-121) == false);
  res.push_back(Solution::isPalindrome(10) == false);
  
  return 0;
}