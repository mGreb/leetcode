/*
 * 70. Climbing Stairs
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * */

#include <iostream>

class Solution {
public:
	int climbStairs(int n) {
		if (n < 4)
			return n;
		int i1 = 1;
		int i2 = 2;
		for (int i = 3; i <= n; ++i)
		{
			int i_new = i1 + i2;
			i1 = i2;
			i2 = i_new;
		}
		
		return i2;
	}
};

int main()
{
    Solution s;
    std::cout << s.climbStairs(1) << std::endl;
    std::cout << s.climbStairs(2) << std::endl;
    std::cout << s.climbStairs(3) << std::endl;
    std::cout << s.climbStairs(4) << std::endl;
    std::cout << s.climbStairs(5) << std::endl;
    std::cout << s.climbStairs(6) << std::endl;
    return 0;
}
