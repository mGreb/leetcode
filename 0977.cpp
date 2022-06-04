/*
 * 977. Squares of a Sorted Array
 * Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 * */

#include <vector>

class Solution {
public:
	std::vector<int> sortedSquares(const std::vector<int>& nums) {
		if (nums.empty())
			return {};
		
		const size_t n = nums.size();
		std::vector<int> res(n);
		
		int l = 0;
		int r = n-1;
		int res_pos = n-1;
		
		while (l <= r) {
			if (abs(nums[l]) > abs(nums[r])) {
				res[res_pos] = nums[l] * nums[l];
				++l;
			} else {
				res[res_pos] = nums[r] * nums[r];
				--r;
			}
			--res_pos;
		}
		
		return res;
	}
};

int main() {
    Solution s;
    const bool res01 = s.sortedSquares({ -4,-1,0,3,10 }) == std::vector<int>{0,1,9,16,100};
    const bool res02 = s.sortedSquares({ -7,-3,2,3,11 }) == std::vector<int>{4,9,9,49,121};
    return 0;
}