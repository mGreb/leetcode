#include <vector>

class Solution {
public:
  int search(const std::vector<int>& nums, int target) {
    if (nums.empty())
      return -1;
    
    size_t left = 0;
    size_t right = nums.size() - 1;
    
    while (left < right) {
      const size_t mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    
    if (nums[left] == target)
      return left;
    else
      return -1;
  }
};

int main() {
  Solution s;
  const bool res0 = s.search({1,3,5}, 3) == 1;
  const bool res1 = s.search({-1,0,3,5,9,12}, 9) == 4;
  const bool res2 = s.search({-1,0,3,5,9,12}, 2) == -1;
  const bool res3 = s.search({0}, 0) == 0;
  const bool res4 = s.search({}, 999) == -1;
  const bool res5 = s.search({2, 3}, 2) == 0;
  const bool res6 = s.search({-1, 2}, 2) == 1;
  const bool res7 = s.search({-1, 1}, 2) == -1;
  const bool res8 = s.search({-1}, 2) == -1;
  return 0;
}