/*20. Valid Parentheses
 * Easy
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * */

#include <string>
#include <cmath>
#include <stack>

class Solution {
public:
	// slow and makes extra copy of s
	bool isValid_old(std::string s) {
		if (s.size() < 2)
			return false;
		int pos = 0;
		while (pos + 1 < s.size()) {
			const bool is_round  = s[pos] == '(' && s[pos + 1] == ')';
			const bool is_square = s[pos] == '[' && s[pos + 1] == ']';
			const bool is_curved = s[pos] == '{' && s[pos + 1] == '}';
			if (is_curved || is_round || is_square) {
				s.erase(pos, 2);
				pos = std::max(0, pos - 1);
			} else {
				++pos;
			}
		}
		return s.empty();
	}
	
	// fast, uses stack
	bool isValid(const std::string& s) {
		std::stack<char> stack;
		for (const auto& c : s) {
			if (c == '(' || c == '[' || c == '{')
				stack.push(c);
			else {
				if (stack.empty())  // pop an empty stack -> segfault
					return false;
				const char& top = stack.top();
				if (top == '(' && c != ')' || top == '[' && c != ']' || top == '{' && c != '}')
					return false;
				stack.pop();
			}
		}
		return stack.empty();
	}
};

int main() {
	Solution s;
	
	const bool res1 = s.isValid("()") == true;
	const bool res2 = s.isValid("()[]{}") == true;
	const bool res3 = s.isValid("(}") == false;
	const bool res4 = s.isValid("{[]}") == true;
	const bool res5 = s.isValid("{[}]") == false;
	const bool res6 = s.isValid("(])") == false;
	
	return 0;
}