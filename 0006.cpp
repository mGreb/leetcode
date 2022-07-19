/*6. Zigzag Conversion
 * Medium
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * Example 3:
 * Input: s = "A", numRows = 1
 * Output: "A"
 * Constraints:
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000 */

#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
  std::string convert(const std::string& s, const int numRows) {
    if (numRows == 1)
      return s;
    std::vector<std::string> matrix(numRows);
    for (size_t i = 0; i < matrix.size(); ++i)
      matrix[i].reserve(2 * std::ceil((double)s.size() / numRows));
    size_t cnt = 0;
    int x = 0;
    bool down = true;
    while (cnt < s.size()) {
      matrix[x].push_back(s[cnt++]);
      
      if (x == numRows - 1)
        down = false;
      
      if (x == 0)
        down = true;
      
      if (down)
        ++x;
      else
        --x;
    }
    
    std::string res;
    for (const auto& i: matrix)
      res.append(i);
    return res;
  }
};

int main() {
  Solution s;
  const bool res0 = s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR";
  const bool res1 = s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI";
  const bool res2 = s.convert("PAYPALISHIRING", 40) == "PAYPALISHIRING";
  const bool res3 = s.convert("A", 1) == "A";
  const bool res4 = s.convert("AB", 1) == "AB";
  return 0;
}
