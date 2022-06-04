/*
 * 4. Median of Two Sorted Arrays
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 * */

#include <vector>

class Solution {
private:
    void advance(size_t& cnt, int& val1, int& val2, const std::vector<int>& v) {
        val1 = val2;
        val2 = v[cnt];
        ++cnt;
    }
    void compute_median_position(size_t n, size_t &median1, size_t &median2) {
        const bool odd = n % 2 == 0;
        median1 = odd ? n / 2 - 1 : n / 2;
        median2 = n / 2;
    }
    double calc_median(const std::vector<int>& v) {
        const size_t n = v.size();
        size_t median1 = 0, median2 = 0;
        compute_median_position(n, median1, median2);
        const bool odd = n % 2 == 0;
        if (odd)
            return 0.5 * (v[median1] + v[median2]);
        else
            return v[median2];
    }
public:
    double findMedianSortedArrays(std::vector<int> nums1, std::vector<int> nums2) {
        const size_t n = nums1.size();
        const size_t m = nums2.size();

        if (n == 0 && m == 0) return 0;
        if (n == 1 && m == 0) return nums1[0];
        if (n == 0 && m == 1) return nums2[0];
        if (n == 1 && m == 1) return 0.5 * (nums1[0] + nums2[0]);
        
        if (n == 0 && m >= 2) return calc_median(nums2);
        if (n >= 2 && m == 0) return calc_median(nums1);

        // calculate median positions
        size_t median1 = 0, median2 = 0;
        compute_median_position(n + m, median1, median2);
        
        int val1 = nums1[0];
        int val2 = nums1[0];
        size_t cnt_total = 0;
        size_t cnt1 = 0;
        size_t cnt2 = 0;

        while (cnt_total <= median2) {
            
            if (cnt1 == n && cnt2 < m)
                advance(cnt2, val1, val2, nums2);
            
            if (cnt2 == m && cnt1 < n)
                advance(cnt1, val1, val2, nums1);
            
            if (cnt1 < n && cnt2 < m) {
                if (nums1[cnt1] < nums2[cnt2])
                    advance(cnt1, val1, val2, nums1);
                else
                    advance(cnt2, val1, val2, nums2);
            }
            
            cnt_total = cnt1 + cnt2;
        }

        const bool odd = (n + m) % 2 == 0;
        if (!odd)
            return val2;
        else
            return 0.5 * (val1 + val2);
    }
};

int main() {
    Solution s;
    const bool res01 = 0 == s.findMedianSortedArrays({}, {});
    const bool res02 = 1 == s.findMedianSortedArrays({1}, {});
    const bool res03 = 1 == s.findMedianSortedArrays({}, {1});
    const bool res04 = 1.5 == s.findMedianSortedArrays({}, {1, 2});
    const bool res05 = 1.5 == s.findMedianSortedArrays({1, 2}, {});
    const bool res06 = 2 == s.findMedianSortedArrays({}, {1, 2, 3});
    const bool res07 = 2 == s.findMedianSortedArrays({1, 2, 3}, {});
    const bool res08 = 1.5 == s.findMedianSortedArrays({1}, {2});
    const bool res09 = 2 == s.findMedianSortedArrays({1, 3}, {2});
    const bool res10 = 2 == s.findMedianSortedArrays({1}, {2, 3});
    const bool res11 = 2.5 == s.findMedianSortedArrays({1, 2}, {3, 4});
    const bool res12 = 2.5 == s.findMedianSortedArrays({1}, {2, 3, 4});
    return 0;
}
