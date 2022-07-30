#include <vector>

class Solution {
public:
  int search(const std::vector<int>& nums, int target) {
    size_t l = 0;
    size_t r = nums.size() - 1;
    
    while (l <= r) {
      const size_t m = (l + r) / 2;
      
      while (nums[l] == nums[r] && l < r) {
        ++l;
      }
      
      if (nums[m] == target || nums[r] == target || nums[l] == target)
        return true;
      
      const int l_val = nums[l];
      const int m_val = nums[m];
      const int r_val = nums[r];
      
      if (l_val <= m_val) {  // left part is sorted
        if (l_val <= target && target <= m_val) // target in the left interval
          r = m;
        else
          l = m + 1;
      } else if (m_val <= r_val) { // right part is sorted
        if (m_val <= target && target <= r_val)  // target in the right interval
          l = m + 1;
        else
          r = m;
      }
    }
    
    return false;
  }
};

int main() {
  Solution s;
  std::vector<bool> res;
  res.push_back(s.search({1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1}, 2) == true);
  res.push_back(s.search({1,2,1}, 1) == true);
  res.push_back(s.search({1,0,1,1,1}, 0) == true);
  res.push_back(s.search({2,5,6,0,0,1,2}, 0) == true);
  res.push_back(s.search({2,5,6,0,0,1,2}, 3) == false);
  res.push_back(s.search({3,3,1}, 3) == true);
  res.push_back(s.search({3,3,1,1}, 1) == true);
  res.push_back(s.search({1,3,3,5,5}, 3) == true);
  res.push_back(s.search({4,5,6,6,7,0,0,1,2}, 0) == true);
  res.push_back(s.search({4,5,5,5,6,7,0,1,2,2,2}, 3) == false);
  res.push_back(s.search({1}, 0) == false);
  return 0;
}
