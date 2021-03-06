/*
 * 7. Reverse Integer
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 * */

#include <climits>
#include <cmath>
#include <vector>

class Solution {
public:
	static int reverse(int x) {
		
		if (x <= INT_MIN || x >= INT_MAX)
			return 0;
		
		int result = 0;
		int shift = 10;
		
		int sign = std::copysign(1, x);
		x = abs(x);
		
		while (x != 0) {
			int temp = x % 10;
			
			x = x / 10;
			
			if (result > (INT_MAX - temp) / shift)
				return 0;
			else
				result = result * shift + temp;
		}
		return result * sign;
	}
};

int main() {
	std::vector<bool> res;
	res.push_back(Solution::reverse(123) == 321);
	res.push_back(Solution::reverse(-123) == -321);
	res.push_back(Solution::reverse(120) == 21);
	return 0;
}