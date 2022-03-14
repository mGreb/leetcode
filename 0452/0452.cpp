/*
 * 452. Minimum Number of Arrows to Burst Balloons
 * There are some spherical balloons taped onto a flat wall that represents the XY-plane.
 * The balloons are represented as a 2D integer array points where points[i] = [xstart, xend]
 * denotes a balloon whose horizontal diameter stretches between xstart and xend.
 * You do not know the exact y-coordinates of the balloons.
 * Arrows can be shot up directly vertically (in the positive y-direction) from different
 * points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x
 * if xstart <= x <= xend. There is no limit to the number of arrows that can be shot.
 * A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
 * Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 * */

#include <iostream>
#include <ostream>
#include <vector>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>> points) {
        std::sort(points.begin(), points.end(), 
            [](const std::vector<int> &v1, const std::vector<int> &v2){return v1[1] < v2[1];});
        int res = 0, arrow = 0;
        for (size_t i = 0; i < points.size(); ++i)
            if (res == 0 || points[i][0] > arrow)
            {
                ++res;
                arrow = points[i][1];
            }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout << 2 << " " << s.findMinArrowShots({{10, 16}, {2, 8}, {1, 6}, {7, 12}}) << std::endl;
    std::cout << 4 << " " << s.findMinArrowShots({{1, 2}, {3, 4}, {5, 6}, {7, 8}}) << std::endl;
    std::cout << 2 << " " << s.findMinArrowShots({{1, 2}, {2, 3}, {3, 4}, {4, 5}}) << std::endl;
    return 0;
}
