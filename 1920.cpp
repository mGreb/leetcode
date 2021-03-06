/*
 * 1920. Build Array from Permutation
 * Given a zero-based permutation nums (0-indexed),
 * build an array ans of the same length where ans[i] = nums[nums[i]]
 * for each 0 <= i < nums.length and return it.
 * A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
 * */

#include <vector>

class Solution {
public:
	std::vector<int> buildArray(const std::vector<int>& nums) {
		std::vector<int> res(nums.size());
		for (size_t i = 0; i < nums.size(); ++i)
			res[i] = nums[nums[i]];
		return res;
	}
};

int main() {
	Solution s;
	std::vector<bool> res;
	res.push_back(s.buildArray({5,0,1,2,3,4}) == std::vector<int>{4,5,0,1,2,3});
	return 0;
}