/*
 * 1345. Jump Game IV
 * Given an array of integers arr, you are initially positioned at the first index of the array.
 * In one step you can jump from index i to index:
 *  i + 1 where: i + 1 < arr.length.
 *  i - 1 where: i - 1 >= 0.
 *  j where: arr[i] == arr[j] and i != j.
 *  Return the minimum number of steps to reach the last index of the array.
 * Notice that you can not jump outside of the array at any time.
 * */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

class Solution {
public:
	int minJumps(const std::vector<int>& arr) {
		const int n = arr.size();
		
		if (n <= 1)
			return 0;
		
		std::map<int, std::vector<int>> map;
		for (int i = 0; i < n; ++i)
			map[arr[i]].push_back(i);
		
		std::queue<int> queue;
		queue.push(0);
		
		int step = 0;
		while (!queue.empty())
		{
			++step;
			const int size = queue.size();
			for (int i = 0; i < size; ++i)
			{
				const int j = queue.front();
				queue.pop();
				
				bool pushed_jm1 = false;
				if (j - 1 >= 0 && map.count(arr[j - 1]) > 0)
				{
					queue.push(j - 1);
					pushed_jm1 = true;
				}
				
				bool pushed_jp1 = false;
				if (j + 1 < n && map.count(arr[j + 1]) > 0)
				{
					if (j + 1 == n - 1)
						return step;
					queue.push(j + 1);
					pushed_jp1 = true;
				}
				
				if (map.count(arr[j]) > 0)
				{
					for (int k : map[arr[j]])
						if (k != j && !(pushed_jm1 && k == j - 1) && !(pushed_jp1 && k == j + 1))
						{
							if (k == n - 1)
								return step;
							queue.push(k);
						}
				}
				
				map.erase(arr[j]);
			}
		}
		
		return step;
	}
};

int main()
{
    Solution s;
    std::cout << "3 = " << s.minJumps({100,-23,-23,404,100,23,23,23,3,404}) << std::endl;
    std::cout << "3 = " << s.minJumps({7,7,2,1,7,7,7,3,4,1}) << std::endl;
    return 0;
}