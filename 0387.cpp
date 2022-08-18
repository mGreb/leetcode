/* 387. First Unique Character in a String
 * Easy
 * Given a string s, find the first non-repeating
 * character in it and return its index.
 * If it does not exist, return -1.*/

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    static int firstUniqChar(std::string s) {
        std::unordered_map<int, int> umap;
        for (auto letter: s)
            ++umap[letter];
        
        for (size_t i = 0; i < s.size(); ++i)
            if (umap[s[i]] == 1)
                return i;
        
        return -1;
    }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::firstUniqChar("leetcode") == 0);
  res.push_back(Solution::firstUniqChar("loveleetcode") == 2);
  res.push_back(Solution::firstUniqChar("aabb") == -1);
  return 0;
}