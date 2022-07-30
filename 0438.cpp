#include <vector>
#include <string>
#include <map>

class Solution {
public:
  std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    
    if (p.size() > s.size())
      return {};
    
    std::map<char, int> temp_map, p_map;
    
    for(size_t i = 0; i < p.size(); ++i) { // fill first chunk
      ++temp_map[s[i]];
      ++p_map[p[i]];
    }
    
    std::vector<int> res;
    if (temp_map == p_map)
      res.push_back(0);
    
    for (size_t i = p.size(); i < s.size(); ++i) {
      const size_t window_begin = i - p.size();
      ++temp_map[s[i]];
      --temp_map[s[window_begin]];
      if (temp_map[s[window_begin]] <= 0)
        temp_map.erase(s[window_begin]);
      if (temp_map == p_map)
        res.push_back(window_begin + 1);
    }
    
    return res;
  }
};

int main() {
  Solution s;
  auto res0 = s.findAnagrams("cbaebabacd", "abc");
  auto res1 = s.findAnagrams("1", "abc");
  auto res2 = s.findAnagrams("abab", "ab");
  return 0;
}
