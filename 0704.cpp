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
  std::vector<bool> res;
  res.push_back(s.search({1,3,5}, 3) == 1);
  res.push_back(s.search({-1,0,3,5,9,12}, 9) == 4);
  res.push_back(s.search({-1,0,3,5,9,12}, 2) == -1);
  res.push_back(s.search({0}, 0) == 0);
  res.push_back(s.search({}, 999) == -1);
  res.push_back(s.search({2, 3}, 2) == 0);
  res.push_back(s.search({-1, 2}, 2) == 1);
  res.push_back(s.search({-1, 1}, 2) == -1);
  res.push_back(s.search({-1}, 2) == -1);
  return 0;
}