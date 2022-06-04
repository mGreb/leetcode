/*26. Remove Duplicates from Sorted Array
 * Easy
 * Given an integer array nums sorted in non-decreasing order,
 * remove the duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same.
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array nums.
 * More formally, if there are k elements after removing the duplicates, then the first
 * k elements of nums should hold the final result.
 * It does not matter what you leave beyond the first k elements.
 * Return k after placing the final result in the first k slots of nums.
 * Do not allocate extra space for another array.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 * */

#include <vector>
#include <cassert>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		size_t last_unique_pos = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
			if (nums[i] != nums[last_unique_pos]) {
				nums[++last_unique_pos] = nums[i];
			}
		}
		return last_unique_pos + 1;
	}
};

int main() {
	Solution s;
	{
		std::vector<int> v = {1, 1, 2};
		std::vector<int> v_new = {1, 2, 2};
		const int res = s.removeDuplicates(v);
		assert (res == 2);
		assert(v == v_new);
	}
	{
		std::vector<int> v = {1, 2, 3};
		std::vector<int> v_new = {1, 2, 3};
		const int res = s.removeDuplicates(v);
		assert (res == 3);
		assert(v == v_new);
	}
	{
		std::vector<int> v = {1, 1, 1};
		std::vector<int> v_new = {1, 1, 1};
		const int res = s.removeDuplicates(v);
		assert (res == 1);
		assert(v == v_new);
	}
	return 0;
}