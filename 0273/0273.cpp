/*
 * 273. Integer to English Words
 * Convert a non-negative integer num to its English words representation.
 * */

#include <string>
#include <array>

class Solution {
private:
    const std::array<std::string, 20> small = { "Zero", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    const std::array<std::string, 10> big = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety" };

    std::array<int, 10> fill_number(int n) {
        std::array<int, 10> number;
        for (int i = 9; i >= 0; --i) {
            number[i] = n % 10;
            n = n / 10;
        }
        return number;
    }

    void make_three(std::string &s, int n1, int n2, int n3) {
        s.clear();

        if (n1 != 0)
            s.append(small[n1]).append(" Hundred");
        
        if (n1 != 0 && n2 != 0)
            s.append(" ");
        
        if (n2 == 1) {
            s.append(small[10 + n3]);
            return;
        }
        
        if (n2 >= 2)
            s.append(big[n2]);
        
        if (!s.empty() && n3 != 0)
            s.append(" ");

        if (n3 != 0)
            s.append(small[n3]);
    }

public:
    std::string numberToWords(int num) {

        if (num <= 19)
            return small[num];

        std::string res;
        std::array<int, 10> number = fill_number(num);
        if (number[0] != 0)
            res.append(small[number[0]]).append(" Billion");

        std::string s;
        make_three(s, number[1], number[2], number[3]);
        
        if (!res.empty() && !s.empty())
            res.append(" ");

        if (!s.empty())
            res.append(s).append(" Million");

        make_three(s, number[4], number[5], number[6]);
        
        if (!res.empty() && !s.empty())
            res.append(" ");

        if (!s.empty())
            res.append(s).append(" Thousand");

        make_three(s, number[7], number[8], number[9]);

        if (!res.empty() && !s.empty())
            res.append(" ");

        if (!s.empty())
            res.append(s);

        return res;
    }
};

int main() {
    Solution s;
    const bool res1 = s.numberToWords(1) == "One";
    const bool res2 = s.numberToWords(20) == "Twenty";
    const bool res21 = s.numberToWords(30) == "Thirty";
    const bool res22 = s.numberToWords(101) == "One Hundred One";
    const bool res3 = s.numberToWords(123) == "One Hundred Twenty Three";
    const bool res4 = s.numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five";
    const bool res5 = s.numberToWords(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
    return 0;
}
