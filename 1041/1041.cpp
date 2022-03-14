/*
 * 1041. Robot Bounded In Circle
 * On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:
 *
 *  The north direction is the positive direction of the y-axis.
 *  The south direction is the negative direction of the y-axis.
 *  The east direction is the positive direction of the x-axis.
 *  The west direction is the negative direction of the x-axis.
 *
 * The robot can receive one of three instructions:
 *
 *  "G": go straight 1 unit.
 *  "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
 *  "R": turn 90 degrees to the right (i.e., clockwise direction).
 *
 * The robot performs the instructions given in order, and repeats them forever.
 *
 * Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
 * */

#include <string>
#include <set>
#include <cmath>

class Solution {
private:
	int x = 0, y = 0;
	int deg = 0;
	void rotate(int dir)
	{
		deg += dir;
		if (deg == 360) { deg =   0; return; }
		if (deg  <   0) { deg = 270; return; }
		if (deg  > 360) { deg =  90; return; }
	}
	void move()
	{
		switch (deg)
		{
			case   0 : --x; break;
			case  90 : ++y; break;
			case 180 : ++x; break;
			case 270 : --y; break;
			default  :      break;
		}
	}
public:
	bool isRobotBounded(std::string instructions) {
		size_t i = 0, total = 0;
		const int runs = 5;
		std::set<std::pair<int, int>> places;
		int places_size[runs];
		int run = 0;
		while (true)
		{
			switch (instructions[i])
			{
				case 'L': rotate(-90); break;
				case 'R': rotate(90); break;
				case 'G': move();          break;
				default:                  break;
			}
			places.insert({x, y});
			++i;
			if (i >= instructions.size())
			{
				i = 0;
				places_size[run] = places.size();
				run++;
			}
			++total;
			if (total > instructions.size() * runs)
			{
				if (places_size[runs-2] == places_size[runs-1])
					return true;
				else
					return false;
			}
		}
	}
};

int main()
{
    Solution s;
    bool res = s.isRobotBounded("RGRRRLGGRRGRRRLLGRLRGGRLRRLRLLGGRGRRRRLG");
    return 0;
}
