/*
 * 53. Maximum Subarray
 * Given an integer array nums, find the contiguous subarray
 * (containing at least one number) which has the largest sum and return its sum.
 * A subarray is a contiguous part of an array.
 */

#include <vector>

class Solution {
public:
	int maxSubArray(const std::vector<int>& nums) {
		int cur_sum = nums[0];
		int max_sum = nums[0];
		int sz = nums.size();
		for (int i = 1; i < sz; ++i) {
			cur_sum = std::max(nums[i], cur_sum + nums[i]);
			max_sum = std::max(cur_sum, max_sum);
		}
		return max_sum;
	}
};

int main() {
	Solution s;
	const bool res1 = s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) == 6;
	const bool res2 = s.maxSubArray({1}) == 1;
	const bool res3 = s.maxSubArray({5,4,-1,7,8}) == 23;
	return 0;
}