/*
 * 520. Detect Capital
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 *  All letters in this word are capitals, like "USA".
 *  All letters in this word are not capitals, like "leetcode".
 *  Only the first letter in this word is capital, like "Google".
 * Given a string word, return true if the usage of capitals in it is right.
 * */

#include <string>
#include <cassert>

class Solution {
public:
    // valid cases:
    // 1 - all letters are capitals
    // 2 - no capitals at all
    // 3 - only first letter is capital
    bool detectCapitalUse(std::string word) {
        const size_t n = word.size();
        {
            bool all_small = true;
            for (size_t i = 0; i < n; ++i) {
                if (word[i] < 'a') {
                    all_small = false;
                    break;
                }
            }
            if (all_small) return all_small;
        }
        {
            bool all_big = true;
            for (size_t i = 0; i < n; ++i) {
                if (word[i] > 'Z') {
                    all_big = false;
                    break;
                }
            }
            if (all_big) return all_big;
        }
        {
            bool first_big = word[0] < 'a' ? true : false;
            if (first_big) {
                for (size_t i = 1; i < n; ++i) {
                    if (word[i] < 'a') {
                        first_big = false;
                        break;
                    }
                }
            }
            if (first_big) return first_big;
        }
        return false;
    }
};

int main() {
    Solution s;
    const bool res1 = s.detectCapitalUse("USA") == true;
	const bool res2 = s.detectCapitalUse("FlaG") == false;
	const bool res3 = s.detectCapitalUse("Google") == true;
	const bool res4 = s.detectCapitalUse("leetcode") == true;
	return 0;
}
