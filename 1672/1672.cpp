/*
 * 1672. Richest Customer Wealth
 * You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the ith
 * customer has in the jth bank. Return the wealth that the richest customer has.
 * A customer's wealth is the amount of money they have in all their bank accounts.
 * The richest customer is the customer that has the maximum wealth.
 * */

#include <vector>

class Solution {
public:
	int maximumWealth(const std::vector<std::vector<int>>& accounts) {
		int max = accounts[0][0];
		const size_t n = accounts.size();
		for (size_t i = 0; i < n; ++i) {
			int sum = 0;
			const size_t m = accounts[i].size();
			const std::vector<int> &v = accounts[i];
			for (size_t j = 0; j < m; ++j)
				sum += v[j];
			max = std::max(max, sum);
		}
		return max;
	}
};

int main() {
	Solution s;
	const bool res1 = s.maximumWealth({{1,2,3},{3,2,1}}) == 6;
	return 0;
}