#include <vector>

class Solution {
public:
  int findMin(const std::vector<int>& nums) {
    size_t l = 0;
    size_t r = nums.size() - 1;
    
    while (l != r) {
      const size_t m = (l + r) / 2;
      
      const int l_val = nums[l];
      const int m_val = nums[m];
      const int r_val = nums[r];
      
      if (l_val <= m_val) {  // left part is sorted
        if (l_val > r_val)
          l = m + 1;
        else
          r = m;
      } else if (m_val <= r_val) {
        if (l_val > r_val)
          r = m;
        else
          l = m + 1;
      }
    }
    
    return nums[l];
  }
};

int main() {
  Solution s;
  std::vector<bool> res;
  res.push_back(s.findMin({3,1,2}) == 1);
  res.push_back(s.findMin({11,13,15,17}) == 11);
  res.push_back(s.findMin({4,5,6,7,0,1,2}) == 0);
  res.push_back(s.findMin({3,4,5,1,2}) == 1);
  res.push_back(s.findMin({3,1}) == 1);
  res.push_back(s.findMin({1,3,5}) == 1);
  res.push_back(s.findMin({4,5,6,7,0,1,2}) == 0);
  res.push_back(s.findMin({1}) == 1);
  return 0;
}
