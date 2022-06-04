/*
 * There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
 * A move consists of merging exactly k consecutive piles into one pile,
 * and the cost of this move is equal to the total number of stones in these k piles.
 * Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.
 */

#include <vector>
#include <array>
#include <iostream>
#include <tuple>
#include <map>

enum COST { NODE_COST = 0, PREV_COST = 1 };

class Solution
{
public:
	int mergeStones(const std::vector<int>& stones, int k)
	{
		bool it_is_possible;
		int tree_height = 0;
		std::tie(it_is_possible, tree_height) = check_if_merge_possible(stones.size(), k);

		if (!it_is_possible)
			return -1;

		std::map<std::vector<int>, std::array<int, 2>> first;
		std::map<std::vector<int>, std::array<int, 2>> second;

		// Head node
		first[stones] = { 0, 0 };

		for (int i = 0; i < tree_height - 1; ++i)
		{
			populate_new_layer(first, second, k);

			first = second;
			second.clear();
		}

		const int min_res = first.begin()->second[PREV_COST] + first.begin()->second[NODE_COST];

		return min_res;
	}
protected:
	std::pair<bool, int> check_if_merge_possible(int size, int k)
	{
		if (k <= 1) return { false, 0 };

		int counter = 1;  // account for head node
		while (size != 1 && size > 0)
		{
			size -= k - 1;
			++counter;
		}

		if (size == 1) return { true, counter };
		if (size <= 0) return { false, 0 };

		return { true, counter };
	}
	void populate_new_layer(std::map<std::vector<int>, std::array<int, 2>>& first,
		std::map<std::vector<int>, std::array<int, 2>>& second, int k)
	{
		for (auto& it : first)
		{
			std::array<int, 2>& parent = it.second;
			const std::vector<int> par_data = it.first;

			const int child_num = par_data.size() - k + 1;

			for (int j = 0; j < child_num; ++j)
			{
				std::vector<int> data = calc_new_n(par_data, k, j);
				const int cost = data[j];
				const int prev_cost = parent[PREV_COST] + parent[NODE_COST];

				auto same_child_it = second.find(data);

				if (same_child_it != second.end())
				{
					// compare two children and keep only one
					if (prev_cost < same_child_it->second[PREV_COST])
						same_child_it->second = { cost, prev_cost };
				}
				else
					second[data] = { cost, prev_cost };
			}
		}
	}
	std::vector<int> calc_new_n(const std::vector<int>& n, int k, int pos)
	{
		std::vector<int> new_n(n.size() - k + 1);

		for (int i = 0; i < pos; ++i)
			new_n[i] = n[i];

		for (int i = pos; i < pos + k; ++i)
			new_n[pos] += n[i];

		for (int i = pos + k; i < n.size(); ++i)
			new_n[i - k + 1] = n[i];

		return new_n;
	}
};

int main()
{
	std::vector<int> v = { 3,2,4,1 };
	int k = 2;
	v = { 29, 59, 31, 7, 51, 99, 47, 40, 24, 20, 98, 41, 42, 81, 92, 55 };
	k = 2;
	v = { 95, 54, 31, 48, 44, 96, 99, 20, 51, 54, 18, 85, 25, 84, 91, 48, 40, 72, 22 };
	k = 2;

	Solution s;
	std::cout << s.mergeStones(v, k) << std::endl;

	return 0;
}
