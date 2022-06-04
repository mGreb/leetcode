/*278. First Bad Version
 * Easy
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check.
 * Since each version is developed based on the previous version,
 * all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
 * which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which returns whether version is bad.
 * Implement a function to find the first bad version.
 * You should minimize the number of calls to the API.
 * */

class Solution {
public:
  bool isBadVersion(int version) {
    return version > 3;
  }
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    if (!isBadVersion(left)) {
      while (true) {
        const int mid = left + (right - left) / 2;
        const bool midIsBad = isBadVersion(mid);
        if (midIsBad)  // move left
          right = mid;
        else  // move right
          left = mid;
        if (right - left == 1) {
          return isBadVersion(left) ? left : right;
        }
      }
    } else
      return left;
  }
};

int main() {
  Solution s;
  const bool res1 = s.firstBadVersion(5) == 4;
  
  return 0;
}
