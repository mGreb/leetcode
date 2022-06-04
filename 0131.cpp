// Given a string s, partition s such that every substring of the partition
// is a palindrome.Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

#include <vector>
#include <string>

class Solution
{
public:
	bool checkIfPal(const std::string &s, int pos1, int pos2)
	{
		while (pos1 <= pos2)
		{
			if(s[pos1] != s[pos2])
				return false;
			++pos1;
			--pos2;
		}
		
		return true;
	}
	
	void fillPalTable(const std::string &s)
	{
		const int n = s.size();
		pal_table.resize(n);
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				if (checkIfPal(s, i, j))
					pal_table[i].emplace_back(std::pair<char, char>{i, j});
	}
	
	void populate(std::vector<std::pair<char, char>> path)
	{
		if (path.back().second == pal_table.size() - 1)
		{
			paths.emplace_back(path);
			return;
		}
		const int next = path.back().second + 1;
		for (int i = 0; i < pal_table[next].size(); ++i)
		{
			path.emplace_back(pal_table[next][i]);
			populate(path);
			path.pop_back();
		}
	}
	
	void fillFromPairs(const std::string &s, std::vector<std::vector<std::string>> &res)
	{
		res.resize(paths.size());
		for (int i = 0; i < paths.size(); ++i)
			for (int j = 0; j < paths[i].size(); ++j)
				res[i].emplace_back(std::string(s.begin() + paths[i][j].first,
					s.begin() + paths[i][j].second + 1));
	}
	
    std::vector<std::vector<std::string>> partition(std::string s)
	{
		fillPalTable(s);
		
		for (int i = 0; i < pal_table[0].size(); ++i)
			populate({ pal_table[0][i] });
		
		std::vector<std::vector<std::string>> res;
		fillFromPairs(s, res);
		
		return res;
    }
private:
	std::vector<std::vector<std::pair<char, char>>> pal_table;
	std::vector<std::vector<std::pair<char, char>>> paths;
};

int main()
{
	Solution s;
	auto r = s.partition("abb");
	return 0;
}
