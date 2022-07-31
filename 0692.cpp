/* 692. Top K Frequent Words
 * Medium
 * Given an array of strings words and an integer k,
 * return the k most frequent strings.
 * Return the answer sorted by the frequency
 * from highest to lowest. Sort the words with
 * the same frequency by their lexicographical order.*/

#include <vector>
#include <string>
#include <map>
#include <queue>

typedef std::pair<std::string_view, size_t> elem;

class Solution {
  struct cmp {
      bool operator() (const elem& a, const elem& b) const {
        if (a.second == b.second)
          return a.first < b.first;
        else
          return a.second > b.second;
      }
  };
public:
  std::vector<std::string> topKFrequent(const std::vector<std::string>& words, int k) {
    
    std::map<std::string_view, size_t> string_count;
    for (const auto& word : words)
      ++string_count[std::string_view(word)];
    
    std::priority_queue<elem, std::vector<elem>, cmp> pr_q;
    for (const auto& item : string_count) {
      pr_q.push(item);
      if (pr_q.size() > k)
        pr_q.pop();
    }
    
    std::vector<std::string_view> res;
    res.reserve(k);
    while (!pr_q.empty()) {
      res.emplace_back(pr_q.top().first);
      pr_q.pop();
    }
    return {res.rbegin(), res.rend()};
  }
};

int main() {
  Solution s;
  auto res0 = s.topKFrequent({"i","love","leetcode","i","love","coding"}, 2);
  auto res1 = s.topKFrequent({"the","day","is","sunny","the","the","the","sunny","is","is"}, 4);
  return 0;
}
