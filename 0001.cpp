/*
 * 1. Two Sum
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 * You can return the answer in any order.
 * */

#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> nums, int target) {
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
      if (m.find(target - nums[i]) != m.end())
        return {i, m[target - nums[i]]};
      else
        m[nums[i]] = i;
    return {0, 0};
  }
};

int main() {
	Solution s;
	const bool res0 = s.twoSum({0,4,3,0}, 0) == std::vector<int>{3,0};
	const bool res1 = s.twoSum({2,7,11,15}, 9) == std::vector<int>{1,0};
	const bool res2 = s.twoSum({3,2,4}, 6) == std::vector<int>{2,1};
	const bool res3 = s.twoSum({3,3}, 6) == std::vector<int>{1,0};
	return 0;
}
