/*
 * 13. Roman to Integer
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *  Symbol       Value
 *  I             1
 *  V             5
 *  X             10
 *  L             50
 *  C             100
 *  D             500
 *  M             1000
 * For example, 2 is written as II in Roman numeral, just two one's added together.
 * 12 is written as XII, which is simply X + II.
 * The number 27 is written as XXVII, which is XX + V + II.
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII.
 * Instead, the number four is written as IV.
 * Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *  I can be placed before V (5) and X (10) to make 4 and 9.
 *  X can be placed before L (50) and C (100) to make 40 and 90.
 *  C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer.
 * */

#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        const size_t n = s.size();
        size_t pos = 0;
        size_t res = 0;
        while (pos < n) {
            switch (s[pos]) {
            case 'M':
                res += 1000;
                ++pos;
                break;
            case 'D':
                res += 500;
                ++pos;
                break;
            case 'C':
                if (pos != n - 1) {
                    if (s[pos + 1] == 'D') {
                        res += 400;
                        pos += 2;
                        break;
                    }
                    if (s[pos + 1] == 'M') {
                        res += 900;
                        pos += 2;
                        break;
                    }
                }
                res += 100;
                ++pos;
                break;
            case 'L':
                res += 50;
                ++pos;
                break;
            case 'X':
                if (pos != n - 1) {
                    if (s[pos + 1] == 'L') {
                        res += 40;
                        pos += 2;
                        break;
                    }
                    if (s[pos + 1] == 'C') {
                        res += 90;
                        pos += 2;
                        break;
                    }
                }
                res += 10;
                ++pos;
                break;
            case 'V':
                res += 5;
                ++pos;
                break;
            case 'I':
                if (pos != n - 1) {
                    if (s[pos + 1] == 'V') {
                        res += 4;
                        pos += 2;
                        break;
                    }
                    if (s[pos + 1] == 'X') {
                        res += 9;
                        pos += 2;
                        break;
                    }
                }
                res += 1;
                ++pos;
                break;
            default:
                break;
            }
        }
        return res;
    }
};

int main() {
	Solution s;
	const bool res1 = s.romanToInt("III") == 3;
	const bool res2 = s.romanToInt("LVIII") == 58;
	const bool res3 = s.romanToInt("MCMXCIV") == 1994;
    return 0;
}
