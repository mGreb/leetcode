/*
 * 62. Unique Paths
 * There is a robot on an m x n grid.
 * The robot is initially located at the top-left corner (i.e., grid[0][0]).
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 * The robot can only move either down or right at any point in time.
 * Given the two integers m and n, return the number of possible unique
 * paths that the robot can take to reach the bottom-right corner.
 * The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
 * */

class Solution {
private:
	long long int factorial(int x, int from) {
		if (x == 0) return 1;
		if (x == 1) return 1;
		long long int ans = 1;
		for (int i = from; i <= x; ++i)
			ans *= i;
		return ans;
	}
public:
	int uniquePaths(int m, int n) {
		int max = n-1, min = m-1;
		if (m-1 > max) { max = m-1; min = n-1;}
		return factorial(m+n-2, max+1) / factorial(min, 1);
	}
};


int main() {
	Solution s;
	const bool res1 = s.uniquePaths(3, 7) == 28;
	const bool res2 = s.uniquePaths(3, 2) == 3;
	return 0;
}