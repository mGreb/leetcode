/* 229. Majority Element II
 * Medium
 * Given an integer array of size n,
 * find all elements that appear more than ⌊ n/3 ⌋ times.*/

#include <vector>

class Solution {
public:
  static std::vector<int> majorityElement(const std::vector<int>& nums) {
    
    if (nums.size() <= 1)
      return nums;
    
    if (nums.size() == 2) {
      if (nums[0] == nums[1])
        return {nums[0]};
      else
        return nums;
    }
    
    // Boyer-Moore algorithm
    int num1 = -1, num2 = -2;
    size_t cnt1 = 0, cnt2 = 0;
    
    for (auto num : nums) {
      if (num1 == num) {
        ++cnt1;
      } else if (num2 == num) {
        ++cnt2;
      } else if (cnt1 == 0) {
        num1 = num;
        cnt1 = 1;
      } else if (cnt2 == 0) {
        num2 = num;
        cnt2 = 1;
      } else {
        --cnt1;
        --cnt2;
      }
    }
    
    size_t check1 = 0;
    size_t check2 = 0;
    
    for (auto num : nums) {
      if (num == num1)
        ++check1;
      if (num == num2)
        ++check2;
    }
    
    std::vector<int> res;
    if (check1 > nums.size() / 3)
      res.push_back(num1);
    if (num1 != num2 && check2 > nums.size() / 3)
      res.push_back(num2);
    
    return res;
  }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::majorityElement({3,2,3}) == std::vector<int>{3});
  res.push_back(Solution::majorityElement({1}) == std::vector<int>{1});
  res.push_back(Solution::majorityElement({1,2}) == std::vector<int>{1,2});
  res.push_back(Solution::majorityElement({2,2}) == std::vector<int>{2});
  res.push_back(Solution::majorityElement({3,3,4}) == std::vector<int>{3});
  res.push_back(Solution::majorityElement({1,1,2,3,4,1,1,5,6,7,1,1,8,9,10,1,11,12,13,14}) == std::vector<int>{1});
  return 0;
}
