/*
 * 941. Valid Mountain Array
 * Given an array of integers arr, return true if and only if it is a valid mountain array.
 * Recall that arr is a mountain array if and only if:
 *  arr.length >= 3
 *  There exists some i with 0 < i < arr.length - 1 such that:
 *      arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 *      arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * */

#include <vector>

class Solution {
public:
    static bool validMountainArray(std::vector<int> arr) {
        const size_t n = arr.size();
        if (n < 3)
            return false;
        size_t i = 0;
        size_t j = 1;
        while (arr[i] < arr[j]) {
            ++i;
            ++j;
            if (j > n - 1)
                return false;
        }
        if (i == 0)
            return false;
        while (arr[i] > arr[j]) {
            ++i;
            ++j;
            if (j > n - 1)
                break;
        }
        return i == n - 1;
    }
};

int main() {
    std::vector<bool> res;
    res.push_back(Solution::validMountainArray({ 1, 2, 3, 2, 1 }) == true);
    res.push_back(Solution::validMountainArray({ 1, 2 }) == false);
    res.push_back(Solution::validMountainArray({ 2, 1 }) == false);
    res.push_back(Solution::validMountainArray({ 3, 5, 5 }) == false);
    res.push_back(Solution::validMountainArray({ 0, 3, 2, 1 }) == true);
    res.push_back(Solution::validMountainArray({ 0, 2, 2, 1 }) == false);
    res.push_back(Solution::validMountainArray({ 0, 2, 3, 1 }) == true);
    res.push_back(Solution::validMountainArray({ 1, 2, 3, 4 }) == false);
    res.push_back(Solution::validMountainArray({ 4, 3, 2, 1 }) == false);
    res.push_back(Solution::validMountainArray({ 1, 1, 1, 1 }) == false);
    return 0;
}