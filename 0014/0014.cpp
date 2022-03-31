/*14. Longest Common Prefix
 * Easy
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * */

#include <vector>
#include <string>

class Solution {
public:
	std::string longestCommonPrefix(const std::vector<std::string>& strs) {
		const std::string& shortest = *std::min_element(strs.begin(), strs.end(),
												  [](const std::string& s1, const std::string& s2){return s1.size() < s2.size();});
		std::string prefix;
		for (size_t i = 0; i < shortest.size(); ++i) {
			for (size_t j = 0; j < strs.size(); ++j) {
				if (shortest[i] != strs[j][i])
					return prefix;
			}
			prefix += shortest[i];
		}
		return prefix;
	}
};

int main() {
	
	Solution s;
	
	const bool res1 = s.longestCommonPrefix({"flower","flow","flight"}) == "fl";
	const bool res2 = s.longestCommonPrefix({"dog","racecar","car"}) == "";
	
	return 0;
}
