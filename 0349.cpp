/* 349. Intersection of Two Arrays
 * Easy
 * Given two integer arrays nums1 and nums2,
 * return an array of their intersection.
 * Each element in the result must be unique
 * and you may return the result in any order.*/

#include <vector>
#include <unordered_set>

class Solution {
public:
  static std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> elems1(nums1.begin(), nums1.end());
    std::vector<int> res;
    for (auto item: nums2)
      if(elems1.count(item)) {
        res.push_back(item);
        elems1.erase(item);
      }
    return res;
  }
};

// 1. make unordered set from the first vector
// 2. for every element second vector, check if it is in the unordered set
// 3. if it is, add element to the result and erase it from the unordered set
// complexity: O(n)

int main() {
  std::vector<bool> res;
  res.push_back(Solution::intersection({1,2,2,1}, {2,2}) == std::vector<int>{2});
  res.push_back(Solution::intersection({4,9,5}, {9,4,9,8,4}) == std::vector<int>{9,4});
  return 0;
}
