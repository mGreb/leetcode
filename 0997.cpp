/*
 * 997. Find the Town Judge
 * In a town, there are n people labeled from 1 to n.
 * There is a rumor that one of these people is secretly the town judge.
 * If the town judge exists, then:
 *  The town judge trusts nobody.
 *  Everybody (except for the town judge) trusts the town judge.
 *  There is exactly one person that satisfies properties 1 and 2.
 * You are given an array trust where trust[i] = [ai, bi] representing that the
 * person labeled ai trusts the person labeled bi.
 * Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
 * */

#include <iostream>
#include <vector>

class Solution {
public:
	int findJudge(int n, std::vector<std::vector<int>>& trust) {
		std::vector<int> stats(n, 0);
		
		for (size_t i = 0; i < trust.size(); ++i)
		{
			const int truster = trust[i][0] - 1;
			const int trustee = trust[i][1] - 1;
			
			stats[truster] -= 1;
			stats[trustee] += 1;
		}
		
		for (size_t i = 0; i < stats.size(); ++i)
			if (stats[i] == n - 1)
				return i + 1;
		
		return -1;
	}
};
int main()
{
    int n = 2;
    std::vector<std::vector<int>> trust = {{1, 2}};
    n = 3;
    trust = {{1, 3}, {2, 3}};
    n = 3;
    trust = {{1, 3}, {2, 3}, {3, 1}};
	Solution s;
	std::cout << s.findJudge(n, trust) << std::endl;
	
	return 0;
}
