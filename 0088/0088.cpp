/*
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 *
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 *
 * The final sorted array should not be returned by the function, but instead be stored
 * inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first
 * m elements denote the elements that should be merged, and the last n elements are set to
 * 0 and should be ignored. nums2 has a length of n.
 */

#include <vector>
#include <cassert>
#include <iostream>

class Solution {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		int last = m + n - 1;
		--m;
		--n;
		
		while (m >= 0 || n >= 0)
		{
			if (m >= 0)
			{
				if (n >= 0)
				{
					if (nums1[m] > nums2[n])
					{
						nums1[last] = nums1[m];
						--m;
						--last;
					}
					else
					{
						nums1[last] = nums2[n];
						--n;
						--last;
					}
				}
				else  // n == -1
				{
					nums1[last] = nums1[m];
					--m;
					--last;
				}
			}
			else  // m == -1
			{
				if (n >= 0)
				{
					nums1[last] = nums2[n];
					--n;
					--last;
				}
			}
		}
	}
};

int main()
{
	const int size_a = 5;
	const int size_b = 10;
	std::vector<int> a = { 1, 1, 3, 7, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<int> b = { 2, 3, 6, 7, 8, 10, 11, 17, 19, 22 };
	assert(a.size() == 15);
	assert(b.size() == 10);
	Solution s;
	s.merge(a, size_a, b, size_b);
	for (int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
}
