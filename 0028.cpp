/*28. Implement strStr()
 * Easy
 * Implement strStr().
 * Given two strings needle and haystack, return the index of
 * the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Clarification:
 * What should we return when needle is an empty string?
 * This is a great question to ask during an interview.
 * For the purpose of this problem, we will return 0 when needle is an empty string.
 * This is consistent to C's strstr() and Java's indexOf().
 * */

#include <string>

class Solution {
public:
	int strStr(const std::string &haystack, const std::string &needle) {
		if (needle.empty())
			return 0;
		
		if (haystack.empty() || needle.size() > haystack.size())
			return -1;
		
		for (size_t i = 0; i < haystack.size() - needle.size() + 1; ++i) {
			if (haystack[i] == needle[0]) {  // first letter found
				bool found = true;
				for (size_t j = 1; j < needle.size(); ++j) {
					if (haystack[i + j] != needle[j]) {
						found = false;
						break;
					}
				}
				if (found)
					return i;
			}
		}
		
		return -1;
	}
};

int main() {
	Solution s;
	const bool res1 = s.strStr("hello", "ll") == 2;
	const bool res2 = s.strStr("hello", "pew") == -1;
	const bool res3 = s.strStr("hello", "o") == 4;
	const bool res4 = s.strStr("hello", "hello") == 0;
	const bool res5 = s.strStr("hellop", "hello") == 0;
	const bool res6 = s.strStr("hellop", "pew") == -1;
	const bool res7 = s.strStr("mississippi", "issip") == 4;
	return 0;
}