/* 350. Intersection of Two Arrays II
 * Easy
 * Given two integer arrays nums1 and nums2,
 * return an array of their intersection.
 * Each element in the result must appear as many
 * times as it shows in both arrays and you
 * may return the result in any order.*/

#include <vector>
#include <unordered_map>

class Solution {
public:
  static std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_map<int, size_t> elems1;
    for (auto num: nums1)
      ++elems1[num];
    
    std::vector<int> res;
    for (auto item: nums2)
      if(elems1.count(item)) {
        if (elems1[item] > 0) {
          res.push_back(item);
          --elems1[item];
        }
      }
    return res;
  }
};

// 1. make unordered map from the first vector
// 2. for every element in second vector, check if it is in the unordered map
// 3. if it is, add element to the result and reduce element count in unordered map
// complexity: O(n)

int main() {
  std::vector<bool> res;
  res.push_back(Solution::intersect({1,2,2,1}, {2,2}) == std::vector<int>{2,2});
  res.push_back(Solution::intersect({4,9,5}, {9,4,9,8,4}) == std::vector<int>{9,4});
  return 0;
}
