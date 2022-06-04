/*
 * 1. Two Sum
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 * You can return the answer in any order.
 * */

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        int sz = nums.size();
        for (int i = 0; i < sz; ++i)
            for (int j = i + 1; j < sz; ++j)
                if (nums[i] + nums[j] == target)
                    return {i, j};
        return {0, 0};
    }
};

int main() {
	Solution s;
	const bool res1 = s.twoSum({2,7,11,15}, 9) == std::vector<int>{0,1};
	const bool res2 = s.twoSum({3,2,4}, 6) == std::vector<int>{1,2};
	const bool res3 = s.twoSum({3,3}, 6) == std::vector<int>{0,1};
	return 0;
}
