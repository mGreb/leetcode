/*
  You are given a list of songs where the ith song has a duration of time[i] seconds.

  Return the number of pairs of songs for which their total duration in seconds is
  divisible by 60. Formally, we want the number of indices i, j such that i < j with
  (time[i] + time[j]) % 60 == 0.
*/

#include <vector>
#include <array>
#include <cstddef>
#include <iostream>

class Solution {
public:
	static int numPairsDivisibleBy60(const std::vector<int> &time) {
		const size_t n = time.size();
		
		if (n < 2)
			return 0;
		
		// store all remainders
		std::array<size_t, 60> rem_60 = {};
		for (size_t i = 0; i < n; ++i)
			++rem_60[time[i] % 60];
		
		// now, figure out how much pairs possible with this remainders
		size_t result = 0;
		for (size_t i = 1; i < 30; ++i)
			result += rem_60[i] * rem_60[60 - i];
		result += rem_60[0] * (rem_60[0] - 1) / 2 + rem_60[30] * (rem_60[30] - 1) / 2;
		
		return result;
	}
};

int main() {
	std::cout << Solution::numPairsDivisibleBy60({30,20,150,100,40}) << std::endl;
	return 0;
}
