/* 823. Binary Trees With Factors
 * Medium
 * Given an array of unique integers, arr,
 * where each integer arr[i] is strictly greater than 1.
 * We make a binary tree using these integers, and each number may be used for any number of times.
 * Each non-leaf node's value should be equal to the product of the values of its children.
 * Return the number of binary trees we can make.
 * The answer may be too large so return the answer modulo 109 + 7.*/

#include <vector>

class Solution {
public:
  static int numFactoredBinaryTrees(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    const int mod = 1e9+7;
    const int n = arr.size();
    std::vector<long long int> dp(n);
    dp[0] = 1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      const int target = arr[i];
      int p = 0;
      int q = i - 1;
      long long int ways = 1;
      while (p <= q) {  // find pair that gives target using two pointer approach
        long long int mult = (long long int)arr[p] * arr[q];
        if (mult == target) {
          long long int add = dp[p] * dp[q];
          if (p != q)  // if different, we can swap them and get 2x variants
            add *= 2;
          ways += add % mod;
          ++p;
          --q;
        } else if (mult < target) {
          ++p;
        } else if (mult > target) {
          --q;
        }
      }
      ways %= mod;
      dp[i] = ways;
      res = ((int)ways + res) % mod;
    }
    return res;
  }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::numFactoredBinaryTrees({2,4}) == 3);
  res.push_back(Solution::numFactoredBinaryTrees({2,4,5,10}) == 7);
  return 0;
}
