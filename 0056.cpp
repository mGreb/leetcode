/* 56. Merge Intervals
 * Medium
 * Given an array of intervals where intervals[i] = [start_i, end_i],
 * merge all overlapping intervals, and return an array of the
 * non-overlapping intervals that cover all the intervals in the input.*/

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> res = {intervals[0]};
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= res.back()[1]) {  // if intervals overlap
        res.back()[1] = std::max(res.back()[1], intervals[i][1]);
      } else {
        res.emplace_back(intervals[i]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  auto res = s.merge({{1,3},{2,6},{8,10},{15,18}, {14, 19}});
  return 0;
}
