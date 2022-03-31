/*27. Remove Element
 * Easy
 * Given an integer array nums and an integer val, remove all occurrences
 * of val in nums in-place. The relative order of the elements may be changed.
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array nums.
 * More formally, if there are k elements after removing the duplicates, then
 * the first k elements of nums should hold the final result.
 * It does not matter what you leave beyond the first k elements.
 * Return k after placing the final result in the first k slots of nums.
 * Do not allocate extra space for another array.
 * You must do this by modifying the input array in-place with O(1) extra memory.*/

#include <vector>
#include <cassert>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); ++i)
			if(nums[i] != val)
				nums[cnt++] = nums[i];
		return cnt;
	}
};

int main() {
	Solution s;
	{
		std::vector<int> v =     {3, 2, 2, 3};
		std::vector<int> v_new = {2, 2, 3, 3};
		const int res = s.removeElement(v, 3);
		assert (res == 2);
//		assert(v == v_new);
	}
	{
		std::vector<int> v =     {0,1,2,2,3,0,4,2};
		std::vector<int> v_new = {0,1,4,0,3,2,2,2};
		const int res = s.removeElement(v, 2);
		assert (res == 5);
//		assert(v == v_new);
	}
	{
		std::vector<int> v =     {1,1,1,1,1,1,1,1};
		std::vector<int> v_new = {1,1,1,1,1,1,1,1};
		const int res = s.removeElement(v, 2);
		assert (res == 8);
//		assert(v == v_new);
	}
	{
		std::vector<int> v =     {1,1,1,1,1,1,1,1};
		std::vector<int> v_new = {1,1,1,1,1,1,1,1};
		const int res = s.removeElement(v, 1);
		assert (res == 0);
//		assert(v == v_new);
	}
	{
		std::vector<int> v =     {1};
		std::vector<int> v_new = {1};
		const int res = s.removeElement(v, 1);
		assert (res == 0);
//		assert(v == v_new);
	}
	{
		std::vector<int> v =     {2,2,3};
		std::vector<int> v_new = {3,2,2};
		const int res = s.removeElement(v, 2);
		assert (res == 1);
//		assert(v == v_new);
	}
	return 0;
}