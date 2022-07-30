#include <vector>
#include <string>
#include <map>

class Solution {
public:
  bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size())
      return false;
    std::map<char, size_t> map_s, map_t;
    for (size_t i = 0; i < s.size(); ++i) {
      ++map_s[s[i]];
      ++map_t[t[i]];
    }
    return map_s == map_t;
  }
};

int main() {
  Solution s;
  auto res = s.isAnagram("rat", "car");
  return 0;
}
