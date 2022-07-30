/*
 * 74. Search a 2D Matrix
 * Medium
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix.
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 *  Constraints:
 *  m == matrix.length
 *  n == matrix[i].length
 *  1 <= m, n <= 100
 *  -10^4 <= matrix[i][j], target <= 10^4
 * */

#include <vector>

class Solution {
  int search(const std::vector<int>& nums, int target) {
    if (nums.empty())
      return -1;
    
    size_t left = 0;
    size_t right = nums.size() - 1;
    
    while (left < right) {
      const size_t mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    
    return left;
  }
public:
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    if (target < matrix[0][0])
      return false;
    
    std::vector<int> tmp;
    tmp.reserve(matrix.size());
//    for (const auto& item: matrix)
//      tmp.emplace_back(item[0]);
    std::transform(matrix.begin(), matrix.end(), std::back_inserter(tmp), [](const std::vector<int>& a){return a[0];});
    
    int row_num = search(tmp, target);
    if (row_num > 0 && matrix[row_num][0] > target)
      --row_num;
    const int res = search(matrix[row_num], target);
    return matrix[row_num][res] == target;
  }
};

int main()
{
    Solution s;
    const bool res0 = s.searchMatrix({{1,3,5,7}, {10,11,16,20}, {23,30,34,60}}, 3) == true;
    const bool res1 = s.searchMatrix({{1,3,5,7}, {10,11,16,20}, {23,30,34,60}}, 13) == false;
    const bool res2 = s.searchMatrix({{1}}, 1) == true;
    const bool res3 = s.searchMatrix({{1}}, 13) == false;
    return 0;
}
