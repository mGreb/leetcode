/* 443. String Compression
 * Medium
 * Given an array of characters chars, compress it using the following algorithm:
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 * The compressed string s should not be returned separately, but instead, be stored in
 * the input character array chars. Note that group lengths that are 10 or longer will
 * be split into multiple characters in chars.
 * After you are done modifying the input array, return the new length of the array.
 * You must write an algorithm that uses only constant extra space.*/

#include <vector>
#include <string>

class Solution {
  static size_t write_num_at_pos(std::vector<char> &chars, size_t pos, size_t num) {
    if (num == 1)
      return pos;
    const auto s = std::to_string(num);
    for (auto digit: s) {
      chars[pos] = digit;
      ++pos;
    }
    return pos;
  }
  static size_t count_identicals(const std::vector<char>& chars, size_t pos) {
    size_t cnt = 1;
    for (size_t i = pos + 1; i < chars.size(); ++i)
      if (chars[i] == chars[pos])
        ++cnt;
      else
        break;
    return cnt;
  }
public:
  static int compress(std::vector<char>& chars) {
    size_t j = 0;
    size_t i = 0;
    while (i < chars.size()) {
      const size_t num = count_identicals(chars, i);
      chars[j] = chars[i];
      if (num > 1) {
        j = write_num_at_pos(chars, j + 1, num);
        i += num;
      } else{
        ++i;
        ++j;
      }
    }
    return j;
  }
};

int main() {
  std::vector<bool> res;
  {
    std::vector<char> a = {'a', 'a', 'a', 'a', 'b', 'a'};
    const int new_sz = Solution::compress(a);
    a.resize(new_sz);
    res.push_back(a == std::vector<char>{'a', '4', 'b', 'a'});
  }
  {
    std::vector<char> a = {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    const int new_sz = Solution::compress(a);
    a.resize(new_sz);
    res.push_back(a == std::vector<char>{'b', '1', '0'});
  }
  {
    std::vector<char> a = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    const int new_sz = Solution::compress(a);
    a.resize(new_sz);
    res.push_back(a == std::vector<char>{'a', 'b', '1', '0'});
  }
  {
    std::vector<char> a = {'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'd', 'd', 'd'};
    const int new_sz = Solution::compress(a);
    a.resize(new_sz);
    res.push_back(a == std::vector<char>{'a', '3', 'b', '3', 'c', '2', 'd', '3'});
  }
  {
    std::vector<char> a = {'a', 'b', 'c', 'd', 'e'};
    const int new_sz = Solution::compress(a);
    a.resize(new_sz);
    res.push_back(a == std::vector<char>{'a', 'b', 'c', 'd', 'e'});
  }
  {
    std::vector<char> a = {'a', 'a', 'b', 'c', 'd', 'e'};
    const int new_sz = Solution::compress(a);
    a.resize(new_sz);
    res.push_back(a == std::vector<char>{'a', '2', 'b', 'c', 'd', 'e'});
  }
  return 0;
}
