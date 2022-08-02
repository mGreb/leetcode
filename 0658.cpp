/*658. Find K Closest Elements
 * Medium
 * Given a sorted integer array arr, two integers k and x,
 * return the k closest integers to x in the array.
 * The result should also be sorted in ascending order.
 * An integer a is closer to x than an integer b if:
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 * Constraints:
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
*/

#include <vector>

class Solution {
  static size_t dist(int a, int b) {
    return std::abs(a - b);
  }
  
  // if a is closer to x than b
  static bool rule(int a, int b, int x) {
    return dist(a, x) < dist(b, x) || (dist(a, x) == dist(b, x) && a < b);
  }
  
  static size_t find_closest_num(const std::vector<int> &arr, int x) {
    if (x <= arr[0])
      return 0;
    if (x >= arr.back())
      return arr.size() - 1;
    
    const int n = arr.size() - 1;
    int step = std::max(1, n / 2);
    int point = 0;
    bool direction = true; // true - to the right
    while (true) {
      int d = arr[point] - x;
      int d_prev = arr[std::max(0, point - 1)] - x;
      if (d * d_prev <= 0) {
        if (rule(arr[point], std::max(0, arr[point - 1]), x))
          return point;
        else
          return std::max(0, point - 1);
      }
      if (d < 0) {  // need to go to the right
        point += step;
        if (!direction) {
          direction = true;
          step = std::max(1, step / 2);
        }
        continue;
      }
      if (d > 0) {  // need to go to the left
        point -= step;
        if (direction) {
          direction = false;
          step = std::max(1, step / 2);
        }
        continue;
      }
    }
  }
  
public:
  static std::vector<int> findClosestElements(const std::vector<int>& arr, int k, int x) {
    const int n = arr.size();
    if (k == n)
      return arr;
    // 1. find element closest to x
    const int pos = find_closest_num(arr, x);
    // 2. find borders of the interval containing k closest elements
    int left = pos - 1, right = pos + 1;
    for (int i = 0; i < k - 1; ++i) {
      if (left < 0 && right < n) {  // left is out, go right
        ++right;
        continue;
      }
      if (left >= 0 && right >= n) {  // right is out, go left
        --left;
        continue;
      }
      if (rule(arr[left], arr[right], x))
        --left;
      else
        ++right;
    }
    // 3. copy interval into result
    ++left;
    return std::vector<int>{arr.begin() + left, arr.begin() + left + k};
  }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::findClosestElements({1,2,3,4,5}, 4, 3) == std::vector<int>{1,2,3,4});
  res.push_back(Solution::findClosestElements({1,2,3,4,5}, 4, -1) == std::vector<int>{1,2,3,4});
  res.push_back(Solution::findClosestElements({3,5,8,10}, 2, 15) == std::vector<int>{8,10});
  res.push_back(Solution::findClosestElements({0,2,2,3,4,6,7,8,9,9}, 4, 5) == std::vector<int>{3,4,6,7});
  res.push_back(Solution::findClosestElements({1,1,1,10,10,10}, 1, 9) == std::vector<int>{10});
  res.push_back(Solution::findClosestElements({0,1,1,1,2,3,6,7,8,9}, 9, 4) == std::vector<int>{0,1,1,1,2,3,6,7,8});
  res.push_back(Solution::findClosestElements({1,3}, 1, 2) == std::vector<int>{1});
  return 0;
}
