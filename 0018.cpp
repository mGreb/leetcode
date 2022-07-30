#include <vector>
#include <unordered_set>

class Solution {
  struct hash {
      size_t operator()(const std::vector<int>& v) const {
        size_t hash = 1;
        for (auto item : v)
          hash = hash * 10 + item;
        return hash;
      }
  };
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> nums, int target) {
    std::vector<std::vector<int>> res;
    if (nums.size() < 4)
      return res;
    
    std::sort(nums.begin(), nums.end());
    
    std::unordered_set<std::vector<int>, hash> set;
    
    for (size_t i = 0; i < nums.size() - 3; ++i) {  // make this problem simpler
      const long long int target1 = target - nums[i];
      for (size_t j = i + 1; j < nums.size() - 2; ++j) {  // make it even simpler
        const long long int target2 = target1 - nums[j];  // now it is just 2 sum problem
        size_t k = j + 1;
        size_t l = nums.size() - 1;
        while (k < l) {
          const long long int target3 = target2 - nums[k];
          const long long int target4 = target3 - nums[l];
          if (target4 == 0) {
            set.insert({nums[i], nums[j], nums[k], nums[l]});
            ++k;
            --l;
          }
          if (target4 > 0)
            ++k;
          if (target4 < 0)
            --l;
        }
      }
    }
    
    return {set.begin(), set.end()};
  }
};

int main() {
	Solution s;
	auto res0 = s.fourSum({1,0,-1,0,-2,2}, 0);
	auto res1 = s.fourSum({2,2,2,2,2}, 8);
	return 0;
}
