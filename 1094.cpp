/*
   1094. Car Pooling
   Medium
   There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
   You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates
   that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are
   fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
   Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
*/

#include <array>
#include <vector>

using std::vector;

class Solution {
public:
    bool carPooling(vector<vector<int>> trips, int capacity)
	{	
		std::array<int, 1001> path;
    	std::fill(path.begin(), path.end(), 0);

    	for (size_t i = 0; i < trips.size(); ++i)
    	{
    		const int begin = trips[i][1];
    		const int end = trips[i][2];
    		const int passengers = trips[i][0];
    		for (int j = begin; j < end; ++j)
                path[j] += passengers;
    	}

    	for (size_t i = 0; i < path.size(); ++i)
			if (path[i] > capacity)
				return false;

    	return true;
    }
};

int main()
{
	Solution s;
	std::vector<bool> res;
	res.push_back(s.carPooling({{2, 1, 5}, {3, 3, 7}}, 4) == false);
	res.push_back(s.carPooling({ {2, 1, 5}, {3, 3, 7} }, 5) == true);
	res.push_back(s.carPooling( {{2,1,5}, {3,5,7}}, 3) == true);
	return 0;
}
