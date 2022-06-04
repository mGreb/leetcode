/*
 * 12. Integer to Roman
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
 * Given an integer, convert it to a roman numeral.
 * */

#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string res;
        while (num != 0) {
            if (num >= 1000) {
                num -= 1000;
                res += 'M';
                continue;
            }
            if (num >= 900) {
                num -= 900;
                res += "CM";
                continue;
            }
            if (num >= 500) {
                num -= 500;
                res += 'D';
                continue;
            }
            if (num >= 400) {
                num -= 400;
                res += "CD";
                continue;
            }
            if (num >= 100) {
                num -= 100;
                res += 'C';
                continue;
            }
            if (num >= 90) {
                num -= 90;
                res += "XC";
                continue;
            }
            if (num >= 50) {
                num -= 50;
                res += 'L';
                continue;
            }
            if (num >= 40) {
                num -= 40;
                res += "XL";
                continue;
            }
            if (num >= 10) {
                num -= 10;
                res += 'X';
                continue;
            }
            if (num >= 9) {
                num -= 9;
                res += "IX";
                continue;
            }
            if (num >= 5) {
                num -= 5;
                res += 'V';
                continue;
            }
            if (num >= 4) {
                num -= 4;
                res += "IV";
                continue;
            }
            if (num >= 1) {
                num -= 1;
                res += 'I';
                continue;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    const bool res1 = s.intToRoman(1900) == "MCM";
    const bool res2 = s.intToRoman(3) == "III";
    const bool res3 = s.intToRoman(58) == "LVIII";
    const bool res4 = s.intToRoman(1994) == "MCMXCIV";
    return 0;
}
