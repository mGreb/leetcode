/*
 * 2129. Capitalize the Title
 * You are given a string title consisting of one or more words separated by a single space,
 * where each word consists of English letters. Capitalize the string by changing the
 * capitalization of each word such that:
 *  If the length of the word is 1 or 2 letters, change all letters to lowercase.
 *  Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
 * Return the capitalized title.
 * */

#include <string>
#include <vector>

class Solution {
private:
    void process_word(std::string& s, size_t start, size_t end) {
        if (end - start <= 2)
            s[start] = std::tolower(s[start]);
        else
            s[start] = std::toupper(s[start]);

        for (size_t i = start + 1; i < end; ++i)
            s[i] = std::tolower(s[i]);
    }
public:
    // if word is 1-2 letters lenght, transform word to lowercase
    // if word > 2 letters in length, make first letter capital and the rest lowercase
    std::string capitalizeTitle(std::string title) {
        
        const size_t n = title.size();
        // find spaces positions
        std::vector<size_t> spaces;
        for (size_t i = 0; i < n; ++i)
            if (title[i] == ' ')
                spaces.emplace_back(i);
        // single word case
        if (spaces.empty()) {
            process_word(title, 0, title.size());
            return title;
        }
        // process words one by one, first and last words separately as edge cases
        process_word(title, 0, spaces[0]);
        for (size_t i = 0; i < spaces.size() - 1; ++i)
            process_word(title, spaces[i] + 1, spaces[i + 1]);
        process_word(title, spaces.back() + 1, title.size());
        
        return title;
    }
};

int main() {
    Solution s;
    const bool res1 = s.capitalizeTitle("LPJOJ") == "Lpjoj";
    const bool res2 = s.capitalizeTitle("capiTalIze tHe titLe") == "Capitalize The Title";
    const bool res3 = s.capitalizeTitle("First leTTeR of EACH Word") == "First Letter of Each Word";
    const bool res4 = s.capitalizeTitle("i lOve leetcode") == "i Love Leetcode";
    return 0;
}