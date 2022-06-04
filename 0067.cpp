/*
 * 67. Add Binary
 * Given two binary strings a and b, return their sum as a binary string.
 * */

#include <string>
#include <algorithm>

class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		
		std::string& big = a.size() > b.size() ? a : b;
		std::string& small = a.size() <= b.size() ? a : b;
		
		const int big_size = std::max(a.size(), b.size());
		const int small_size = std::min(a.size(), b.size());
		
		std::transform(big.begin(), big.end(), big.begin(), [](char c){return c - '0';});
		std::transform(small.begin(), small.end(), small.begin(), [](char c){return c - '0';});
		
		for (int i = 0; i < small_size; ++i)
			big[i + big_size - small_size] += small[i];
		
		for (int i = big.size() - 1; i >=1; --i)
			if (big[i] > 1) {
				big[i] -= 2;
				big[i - 1] += 1;
			}
		
		if (big.front() > 1) {
			big.front() -= 2;
			big.push_back('0');
			for (int i = big.size() - 1; i > 0; --i)
				big[i] = big[i-1];
			big.front() = 1;
		}
		
		std::transform(big.begin(), big.end(), big.begin(), [](char c){ return c + '0';});
		
		return big;
	}
};

int main()
{
    Solution s;
    const bool res = s.addBinary("11", "1") == "100";
    
    return 0;
}
