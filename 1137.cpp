/* 1137. N-th Tribonacci Number
 * The Tribonacci sequence Tn is defined as follows:
 *  T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 *  Given n, return the value of Tn.*/

#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        int counter = 2;
        while (counter < n)
        {
            const int t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
            ++counter;
        }
        return t2;
    }
};

int main()
{
    Solution s;
    std::vector<bool> res;
    res.push_back(s.tribonacci(4) == 4);
    res.push_back(s.tribonacci(25) == 1389537);
    return 0;
}