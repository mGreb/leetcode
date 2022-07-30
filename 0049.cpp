#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> umap;
    for (const auto& string: strs) {
      std::string sorted = string;
      std::sort(sorted.begin(), sorted.end());
      umap[sorted].emplace_back(string);
    }
    std::vector<std::vector<std::string>> res;
    for (const auto& item : umap)
      res.emplace_back(item.second);
    return res;
  }
};

int main() {
  Solution s;
  auto res = s.groupAnagrams({"eat","tea","tan","ate","nat","bat"});
  return 0;
}
