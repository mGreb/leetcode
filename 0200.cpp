#include <vector>
#include <array>
#include <queue>

class Solution {
  void pushAndMark(const std::vector<std::vector<char>>& grid, int i, int j) {
    const int ip1 = std::min(i+1, n-1), im1 = std::max(i-1, 0);
    const int jp1 = std::min(j+1, m-1), jm1 = std::max(j-1, 0);
    std::array<std::pair<int, int>, 5> coords = {{{i, j}, {ip1, j}, {im1, j}, {i, jm1}, {i, jp1}}};
    for (const auto& item : coords){
      const int x = item.first;
      const int y = item.second;
      if (isNotVisitedLand(grid, x, y)) {
        q.push(item);
        visited[x][y] = true;
      }
    }
  }
  bool isNotVisitedLand(const std::vector<std::vector<char>>& grid, int i, int j) {
    return !visited[i][j] && grid[i][j] == '1';
  }
  int n, m;
  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<bool>> visited;
public:
  int numIslands(const std::vector<std::vector<char>>& grid) {
    int res = 0;
    n = grid.size();
    m = grid[0].size();
    visited.resize(n, std::vector<bool>(m, false));
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (isNotVisitedLand(grid, i, j)) {
          pushAndMark(grid, i, j);
          ++res;
        }
        while (!q.empty()) {
          const auto coords = q.front();
          q.pop();
          pushAndMark(grid, coords.first, coords.second);
        }
      }
    }
    
    return res;
  }
};

int main() {
  bool res0, res1;
  {
    Solution s;
    res0 = s.numIslands({{'1','1','1','1','0'},
                         {'1','1','0','1','0'},
                         {'1','1','0','0','0'},
                         {'0','0','0','0','0'}}) == 1;
  }
  {
    Solution s;
    res1 = s.numIslands({{'1','1','0','0','0'},
                         {'1','1','0','0','0'},
                         {'0','0','1','0','0'},
                         {'0','0','0','1','1'}}) == 3;
  }
  return 0;
}
