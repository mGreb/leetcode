/*374. Guess Number Higher or Lower
 * Easy
 * We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
 * You call a pre-defined API int guess(int num), which returns three possible results:
 * -1: Your guess is higher than the number I picked (i.e. num > pick).
 * 1: Your guess is lower than the number I picked (i.e. num < pick).
 * 0: your guess is equal to the number I picked (i.e. num == pick).
 * Return the number that I picked.
 * Constraints:
 * 1 <= n <= 2^31 - 1
 * 1 <= pick <= n
 * */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include <vector>

class Solution {
public:
  int guess(int num) {
    const int secret = 10;
    if (num > secret) return -1;
    if (num < secret) return 1;
    return 0;
  }
  int guessNumber(int n) {
    long long int left = 0, right = n, mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      int cur_guess = guess(mid);
      if (cur_guess == 0)
        break;
      if (cur_guess == -1)
        right = mid - 1;
      else if (cur_guess == 1)
        left = mid + 1;
    }
    return mid;
  }
};

int main() {
  Solution s;
  std::vector<bool> res;
  res.push_back(s.guessNumber(1'000'000) == 10);
  return 0;
}
