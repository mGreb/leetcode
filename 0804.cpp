#include <vector>
#include <array>
#include <string>
#include <unordered_set>

class Solution {
public:
  static int uniqueMorseRepresentations(const std::vector<std::string>& words) {
    std::array<std::string, 26> let = {{".-","-...","-.-.","-..",".","..-.","--.","....","..",
                                        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                                        "...","-","..-","...-",".--","-..-","-.--","--.."}};
    
    std::unordered_set<std::string> uset;
    
    std::string temp;
    temp.reserve(12);
    for (const auto& word: words) {
      temp.clear();
      for (auto letter: word) {
        temp.append(let[letter - 'a']);
      }
      uset.insert(temp);
    }
    
    return uset.size();
  }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::uniqueMorseRepresentations({"gin","zen","gig","msg"}) == 2);
  res.push_back(Solution::uniqueMorseRepresentations({"a"}) == 1);
  return 0;
}
