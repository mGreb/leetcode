/*
 * 169. Majority Element
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * */

#include <vector>

class Solution {
public:
    int majorityElement(const std::vector<int>& nums) {
        // Boyer-Moore algorithm
        int current = nums[0];
        size_t cnt = 0;
        const size_t n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            if (cnt == 0)
                current = nums[i];
            if (nums[i] == current)
                cnt += 1;
            else
                cnt -= 1;
        }
        return current;
    }
};

int main() {
	Solution s;
	const bool res1 = s.majorityElement({3, 2, 3}) == 3;
	const bool res2 = s.majorityElement({2, 2, 1, 1, 1, 2, 2}) == 2;
	return 0;
}
