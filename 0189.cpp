/*
 * 189. Rotate Array
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 * */

#include <vector>
#include <cassert>
#include <numeric>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        const size_t n = nums.size();
        if (n < 2 || k == 0) return;
        if (k > n) k = k % n;
        size_t iters = 1;
        if (n % k == 0)
            iters = k;
        else
            iters = std::gcd(n, k);
        for (size_t i = 0; i < iters; ++i) {
            size_t pos = i;
            int cur = nums[pos];
            int cur1 = nums[pos];
            while (true) {
                const size_t next = (pos + k) % n;
                cur1 = nums[next];
                nums[next] = cur;
                cur = cur1;
                pos = next;
                if (pos == i)
                    break;
            }
        }
    }
};

int main() {
    Solution s;
    {
        std::vector<int> v = {1,2,3,4,5,6,7};
        s.rotate(v, 1);
        std::vector<int> res = { 7,1,2,3,4,5,6 };
        assert(v == res);
    }
    {
        std::vector<int> v = { 1,2,3,4,5,6,7 };
        s.rotate(v, 3);
        std::vector<int> res = { 5,6,7,1,2,3,4 };
        assert(v == res);
    }
    {
        std::vector<int> v = { 1,2,3,4 };
        s.rotate(v, 2);
        std::vector<int> res = { 3,4,1,2 };
        assert(v == res);
    }
    {
        std::vector<int> v = { 1,2,3,4,5,6 };
        s.rotate(v, 4);
        std::vector<int> res = { 3,4,5,6,1,2 };
        assert(v == res);
    }
    {
        std::vector<int> v = { 1,2 };
        s.rotate(v, 3);
        std::vector<int> res = { 2,1 };
        assert(v == res);
    }
    {
        std::vector<int> v(54);
        std::iota(v.begin(), v.end(), 1);
        s.rotate(v, 45);
        std::vector<int> res = { 10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
            26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,
            49,50,51,52,53,54,1,2,3,4,5,6,7,8,9 };
        assert(v == res);
    }
    
    return 0;
}
