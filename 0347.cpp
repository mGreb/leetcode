/*347. Top K Frequent Elements
 * Medium
 * Given an integer array nums and an integer k,
 * return the k most frequent elements.
 * You may return the answer in any order.*/

#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (auto item : nums)
      ++freq[item];
    
    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (auto item : freq)
      buckets[nums.size() - item.second].push_back(item.first);
    
    std::vector<int> res;
    res.reserve(k);
    for (const auto& bucket : buckets) {
      for(auto item : bucket) {
        res.emplace_back(item);
        if (res.size() == k)
          return res;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  auto res = s.topKFrequent({1,1,1,2,2,3}, 2);
  return 0;
}
