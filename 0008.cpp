/*
 * 8. String to Integer (atoi)
 * Implement the myAtoi(string s) function, which converts a string to
 * a 32-bit signed integer (similar to C/C++'s atoi function).
 * The algorithm for myAtoi(string s) is as follows:
 *  Read in and ignore any leading whitespace.
 *  Check if the next character (if not already at the end of the string) is '-' or '+'.
 *  Read this character in if it is either. This determines if the final result is negative
 *  or positive respectively. Assume the result is positive if neither is present.
 *  Read in next the characters until the next non-digit character or the end of the
 *  input is reached. The rest of the string is ignored.
 *  Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32).
 *  If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
 *  If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp
 *  the integer so that it remains in the range. Specifically, integers less than -231 should
 *  be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
 *  Return the integer as the final result.
 * Note:
 *  Only the space character ' ' is considered a whitespace character.
 *  Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 * */

#include <string>
#include <vector>
#include <climits>

class Solution {
private:
    void ignore_whitespace(const std::string &s, size_t &pos)
    {
        while (s[pos] == ' ' && pos < s.size())
            pos++;
    }
    void ignore_letters(const std::string &s, size_t &pos)
    {
        while (s[pos] > 57 && pos < s.size())
            pos++;
    }
    void ignore_zeros(const std::string &s, size_t &pos)
    {
        while (s[pos] == '0' && pos < s.size())
            ++pos;
    }
    bool is_plus(char c) {return c == '+';}
    bool is_minus(char c) {return c == '-';}
    bool is_digit(char c) {return c >= 48 && c <= 57;}
public:
    int myAtoi(std::string s) {
        if (s.empty())
            return 0;

        size_t l = 0;
        ignore_whitespace(s, l);

        int sign = 1;
        if (is_plus(s[l]))
        {
            sign *= 1;
            ++l;
            if (!is_digit(s[l]))
                return 0;
        }
        if (is_minus(s[l]))
        {
            sign *= -1;
            ++l;
            if (!is_digit(s[l]))
                return 0;
        }
        if (!is_plus(s[l]) && !is_minus(s[l]) && !is_digit(s[l]) || l >= s.size())
            return 0;

        ignore_zeros(s, l);

        std::vector<int> res_vec;
        while (is_digit(s[l]) && l < s.size())
        {
            res_vec.push_back(s[l] - '0');
            ++l;
        }

        int res = 0;
        for (size_t i = 0; i < res_vec.size(); ++i)
        {
            const int digit = res_vec[i];
            
            if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10))
                return sign == 1 ? INT_MAX : INT_MIN;
            
            res = res * 10 + digit;
        }
        return res * sign;
    }
};

int main()
{
    Solution s;
    const bool res01 = s.myAtoi("+-12") == 0;
    const bool res02 = s.myAtoi("  +") == 0;
    const bool res03 = s.myAtoi("42") == 42;
    const bool res04 = s.myAtoi("0042") == 42;
    const bool res05 = s.myAtoi("+0042") == 42;
    const bool res06 = s.myAtoi("-0042") == -42;
    const bool res07 = s.myAtoi("   -42") == -42;
    const bool res08 = s.myAtoi("4193 with words") == 4193;
    const bool res09 = s.myAtoi("with words 4193 with words") == 0;
    const bool res10 = s.myAtoi("999999999999999") == 2147483647;
    const bool res11 = s.myAtoi("-999999999999999") == -2147483648;
    return 0;
}