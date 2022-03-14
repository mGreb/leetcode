/*
 * 1009. Complement of Base 10 Integer
 * The complement of an integer is the integer you get when you flip all
 * the 0's to 1's and all the 1's to 0's in its binary representation.
 * For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
 * Given an integer n, return its complement.
 * */

#include <cmath>

class Solution {
public:
	int bitwiseComplement(int n) {
		if (n == 0) return 1;
		int bits = floor(log2(n)) + 1;
		int comp = ((1 << bits) - 1) ^ n;
		return comp;
	}
};

int main()
{
	Solution s;
	int res = s.bitwiseComplement(0);
	return 0;
}
