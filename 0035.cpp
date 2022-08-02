/*35. Search Insert Position
 * Easy
 * Given a sorted array of distinct integers and a target value,
 * return the index if the target is found.
 * If not, return the index where it would be
 * if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
*/

#include <vector>

class Solution {
public:
  static int searchInsert(const std::vector<int>& nums, int target) {
    const size_t n = nums.size();
    
    if (n == 0 || target < nums[0])
      return 0;
    if (target > nums.back())
      return n;
    
    size_t left = 0, mid = n / 2, right = n - 1;
    while (true) {
      if (nums[left] <= target && nums[mid] > target)
        right = mid;
      else
        left = mid;
      
      mid = left + (right - left) / 2;
      
      if (nums[mid] == target)
        return mid;
      
      if (right - left <= 1)
        return right;
    }
  }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::searchInsert({1,3,5}, 4) == 2);
  res.push_back(Solution::searchInsert({1,4,6,7,8,9}, 6) == 2);
  res.push_back(Solution::searchInsert({1,3,5,6}, 5) == 2);
  res.push_back(Solution::searchInsert({1,3,5,6}, 2) == 1);
  res.push_back(Solution::searchInsert({1,3,5,6}, 7) == 4);
  res.push_back(Solution::searchInsert({1,3,5,6}, -10) == 0);
  res.push_back(Solution::searchInsert({1,3,5,6}, 1) == 0);
  res.push_back(Solution::searchInsert({1,3,5,6}, 3) == 1);
  res.push_back(Solution::searchInsert({1,3,5,6}, 6) == 3);
  res.push_back(Solution::searchInsert({1}, 6) == 1);
  res.push_back(Solution::searchInsert({1}, 1) == 0);
  res.push_back(Solution::searchInsert({1}, 0) == 0);
  return 0;
}