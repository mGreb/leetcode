#include <vector>

class Solution {
public:
  int search(const std::vector<int>& nums, int target) {
    size_t l = 0;
    size_t r = nums.size() - 1;
    
    while (l <= r) {
      const size_t m = (l + r) / 2;
      const int l_val = nums[l];
      const int m_val = nums[m];
      const int r_val = nums[r];
      
      if (m_val == target)
        return m;
      
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
    
    return -1;
  }
};

int main() {
  Solution s;
  std::vector<bool> res;
  res.push_back(s.search({3,1}, 3) == 0);
  res.push_back(s.search({3,1}, 1) == 1);
  res.push_back(s.search({1,3,5}, 3) == 1);
  res.push_back(s.search({4,5,6,7,0,1,2}, 0) == 4);
  res.push_back(s.search({4,5,6,7,0,1,2}, 3) == -1);
  res.push_back(s.search({1}, 0) == -1);
  return 0;
}
