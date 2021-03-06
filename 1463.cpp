/*
 * 1463. Cherry Pickup II
 * You are given a rows x cols matrix grid representing a field of cherries where grid[i][j]
 * represents the number of cherries that you can collect from the (i, j) cell.
 * You have two robots that can collect cherries for you:
 *  Robot #1 is located at the top-left corner (0, 0), and
 *  Robot #2 is located at the top-right corner (0, cols - 1).
 * Return the maximum number of cherries collection using both robots by following the rules below:
 *  From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
 *  When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
 *  When both robots stay in the same cell, only one takes the cherries.
 *  Both robots cannot move outside of the grid at any moment.
 *  Both robots should reach the bottom row in grid.
*/

#include <vector>
#include <iostream>

class Solution {
	int dp(int row, int col1, int col2, const std::vector<std::vector<int>> &grid,
		   std::vector<std::vector<std::vector<int>>> &cache)
	{
	  const int n = (int)grid.size();
	  const int n_0 = (int)grid[0].size();
		if (row < 0 || row >= n
			|| col1 < 0 || col1 >= n_0
			|| col2 < 0 || col2 >= n_0)
			return 0;
		
		if (cache[row][col1][col2] != -1)
			return cache[row][col1][col2];
		
		int result = 0;
		result += grid[row][col1];
		if (col1 != col2)
			result += grid[row][col2];
		
		if (row != n - 1)
		{
			int max = 0;
			for (int new_col1 = col1 - 1; new_col1 <= col1 + 1; ++new_col1)
				for (int new_col2 = col2 - 1; new_col2 <= col2 + 1; ++new_col2)
					max = std::max(max, dp(row + 1, new_col1, new_col2, grid, cache));
			result += max;
		}
		
		cache[row][col1][col2] = result;
		
		return result;
	}
public:
	int cherryPickup(std::vector<std::vector<int>>& grid) {
		const int rows = grid.size();
		const int cols = grid[0].size();
		std::vector<std::vector<std::vector<int>>>
				cache(rows, std::vector<std::vector<int>>(cols, std::vector<int>(cols, -1)));
		return dp(0, 0, cols - 1, grid, cache);
	}
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    const int res = s.cherryPickup(grid);
    std::cout << res << std::endl;
    return 0;
}
