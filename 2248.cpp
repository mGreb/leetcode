/* 2248. Intersection of Multiple Arrays
 * Easy
 * Given a 2D integer array nums where nums[i]
 * is a non-empty array of distinct positive integers,
 * return the list of integers that are present
 * in each array of nums sorted in ascending order. */

#include <vector>
#include <unordered_map>

class Solution {
public:
  static std::vector<int> intersection(const std::vector<std::vector<int>>& nums) {
    std::unordered_map<int, size_t> umap;
    for (const auto& vec: nums)
      for (auto num: vec)
        ++umap[num];
    
    std::vector<int> res;
    for (auto item: umap)
      if (item.second >= nums.size())
        res.push_back(item.first);
      
    std::sort(res.begin(), res.end());
    
    return res;
  }
};


// 1. make unordered map of pairs <element, times the element occurred> from all vectors
// 2. iterate through unordered map, if element occurred equal or more than n times, push it to the result
// 3. sort the result (need to be in ascending order)
// complexity: O(n*m)

int main() {
  std::vector<bool> res;
  res.push_back(Solution::intersection({{1,2}, {2}}) == std::vector<int>{2});
  res.push_back(Solution::intersection({{4,9,5}, {9,4,8}}) == std::vector<int>{4,9});
  res.push_back(Solution::intersection({{3,1,2,4,5},{1,2,3,4},{3,4,5,6}}) == std::vector<int>{3,4});
  res.push_back(Solution::intersection({{1,2,3},{4,5,6}}) == std::vector<int>{});
  return 0;
}
