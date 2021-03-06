/*
 * 121. Best Time to Buy and Sell Stock
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing
 * a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction.
 * If you cannot achieve any profit, return 0.
 * */

#include <vector>

class Solution {
public:
	static int maxProfit(const std::vector<int>& p) {
		int min_price = p[0];
		int max_profit = 0;
		for(size_t i = 0; i < p.size(); ++i) {
			min_price = std::min(p[i], min_price);
			max_profit = std::max(max_profit, p[i] - min_price);
		}
		return max_profit;
	}
};

int main() {
	std::vector<bool> res;
	res.push_back(Solution::maxProfit({7,1,5,3,6,4}) == 5);
	res.push_back(Solution::maxProfit({7,6,4,3,1}) == 0);
	return 0;
}