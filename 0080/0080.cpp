/*
 * 80. Remove Duplicates from Sorted Array II
 * Given an integer array nums sorted in non-decreasing order,
 * remove some duplicates in-place such that each unique element
 * appears at most twice. The relative order of the elements should be kept the same.
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array nums.
 * More formally, if there are k elements after removing the duplicates, then the first
 * k elements of nums should hold the final result.
 * It does not matter what you leave beyond the first k elements.
 * Return k after placing the final result in the first k slots of nums.
 * Do not allocate extra space for another array.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 * Custom Judge:
 * The judge will test your solution with the following code:
 * int[] nums = [...]; // Input array
 * int[] expectedNums = [...]; // The expected answer with correct length
 * int k = removeDuplicates(nums); // Calls your implementation
 * assert k == expectedNums.length;
 * for (int i = 0; i < k; i++) {
 * assert nums[i] == expectedNums[i];
 * }
 * If all assertions pass, then your solution will be accepted.
 * */

#include <cassert>
#include <vector>

class Solution {
private:
    size_t count_dupes(const std::vector<int>& v, size_t ind) {
        const size_t n = v.size();
        size_t cnt = 1;
        for (size_t i = ind; i < n - 1; ++i) {
            if (v[i] == v[i + 1])
                ++cnt;
            else
                break;
        }
        return cnt;
    }
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        size_t pos = 2;
        while (pos < nums.size()) {
            if (nums[pos] == nums[pos - 1] && nums[pos] == nums[pos-2]) {
                
                const size_t dupes = count_dupes(nums, pos);
                
                for (size_t i = pos + dupes; i < nums.size(); ++i)
                    nums[i - dupes] = nums[i];
                
                nums.resize(nums.size() - dupes);
            }
            ++pos;
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    {
        std::vector<int> v = { 1, 1, 1, 2, 2, 3 };
        int res = s.removeDuplicates(v);
        assert(res == 5);
        std::vector<int> v_res = { 1, 1, 2, 2, 3 };
        assert(v == v_res);
    }
    {
        std::vector<int> v = { 0,0,1,1,1,1,2,3,3 };
        int res = s.removeDuplicates(v);
        assert(res == 7);
        std::vector<int> v_res = { 0,0,1,1,2,3,3 };
        assert(v == v_res);
    }
    {
        std::vector<int> v = { 1,1,1,1 };
        int res = s.removeDuplicates(v);
        assert(res == 2);
        std::vector<int> v_res = { 1,1 };
        assert(v == v_res);
    }
    {
        std::vector<int> v = { 1,2,2,2 };
        int res = s.removeDuplicates(v);
        assert(res == 3);
        std::vector<int> v_res = { 1,2,2 };
        assert(v == v_res);
    }
    return 0;
}
