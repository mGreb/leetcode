/*
 * 53. Maximum Subarray
 * Given an integer array nums, find the contiguous subarray
 * (containing at least one number) which has the largest sum and return its sum.
 * A subarray is a contiguous part of an array.
 */

#include <vector>

class Solution {
public:
	static int maxSubArray(const std::vector<int>& nums) {
		int cur_sum = nums[0];
		int max_sum = nums[0];
		for (size_t i = 1; i < nums.size(); ++i) {
			cur_sum = std::max(nums[i], cur_sum + nums[i]);
			max_sum = std::max(cur_sum, max_sum);
		}
		return max_sum;
	}
};

int main() {
	std::vector<bool> res;
	res.push_back(Solution::maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) == 6);
	res.push_back(Solution::maxSubArray({1}) == 1);
	res.push_back(Solution::maxSubArray({5,4,-1,7,8}) == 23);
	return 0;
}
