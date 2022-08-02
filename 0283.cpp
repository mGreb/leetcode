#include <vector>

class Solution {
public:
  static void moveZeroes(std::vector<int>& nums) {
    size_t j = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        std::swap(nums[i], nums[j]);
        ++j;
      }
    }
  }
};

int main() {
  std::vector<int> v = {1};
  Solution::moveZeroes(v);
  
  std::vector<int> v1 = {0, 1};
  Solution::moveZeroes(v1);
  return 0;
}
