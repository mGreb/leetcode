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
#include <vector>

class Solution {
public:
	static int strStr(const std::string &haystack, const std::string &needle) {
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
	std::vector<bool> res;
	res.push_back(Solution::strStr("hello", "ll") == 2);
	res.push_back(Solution::strStr("hello", "pew") == -1);
	res.push_back(Solution::strStr("hello", "o") == 4);
	res.push_back(Solution::strStr("hello", "hello") == 0);
	res.push_back(Solution::strStr("hellop", "hello") == 0);
	res.push_back(Solution::strStr("hellop", "pew") == -1);
	res.push_back(Solution::strStr("mississippi", "issip") == 4);
	return 0;
}