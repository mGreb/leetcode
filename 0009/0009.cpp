/*
 * 9. Palindrome Number
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward.
 * For example, 121 is a palindrome while 123 is not.
 * */

#include <vector>

class Solution {
public:
  bool isPalindrome(const std::vector<int>& x) {
    for (int i = 0; i < x.size() / 2; i++) {
        if (x[i] != x[x.size() - 1 - i])
          return false;
     }
    return true;
  }

  std::vector<int> vecInt(int x) {
    std::vector<int> v;
    do {
      const int y = x % 10;
      v.push_back(y);
      x = x / 10;
    } while (x != 0);
    return v;
  }

  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    return isPalindrome(vecInt(x));
  }

};

int main() {
  Solution s;

  const bool v0 = s.vecInt(5320) == std::vector<int> {0, 2, 3, 5};
  const bool v1 = s.vecInt(202) == std::vector<int> {2, 0, 2};
  const bool v3 = s.vecInt(0) == std::vector<int> {0};
  const bool v4 = s.vecInt(9) == std::vector<int> {9};

  const bool p0 = s.isPalindrome({1, 2, 1}) == true;
  const bool p1 = s.isPalindrome({1, 2, 2, 1}) == true;
  const bool p3 = s.isPalindrome({1, 1, 0, 1}) == false;
  const bool p4 = s.isPalindrome({1, 0}) == false;
  const bool p5 = s.isPalindrome({1}) == true;

  const bool pol0 = s.isPalindrome(121) == true;
  const bool pol1 = s.isPalindrome(-1) == false;
  const bool pol2 = s.isPalindrome(-121) == false;
  const bool pol3 = s.isPalindrome(10) == false;
  
  return 0;
}