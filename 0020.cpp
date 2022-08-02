/*20. Valid Parentheses
 * Easy
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * */

#include <string>
#include <vector>
#include <cmath>
#include <stack>

class Solution {
public:
	// fast, uses stack
	static bool isValid(const std::string& s) {
		std::stack<char> stack;
		for (const auto& c : s) {
			if (c == '(' || c == '[' || c == '{')
				stack.push(c);
			else {
				if (stack.empty())  // pop an empty stack -> segfault
					return false;
				const char& top = stack.top();
				if ((top == '(' && c != ')') || (top == '[' && c != ']') || (top == '{' && c != '}'))
					return false;
				stack.pop();
			}
		}
		return stack.empty();
	}
};

int main() {
	std::vector<bool> res;
	res.push_back(Solution::isValid("()") == true);
	res.push_back(Solution::isValid("()[]{}") == true);
	res.push_back(Solution::isValid("(}") == false);
	res.push_back(Solution::isValid("{[]}") == true);
	res.push_back(Solution::isValid("{[}]") == false);
	res.push_back(Solution::isValid("(])") == false);
	
	return 0;
}
