#include <vector>

class Solution {
public:
  static int maxArea(std::vector<int>& height) {
    int max = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
      max = std::max(max, std::min(height[l], height[r]) * (r - l));
      if (height[l] < height[r])
        ++l;
      else
        --r;
    }
    return max;
  }
};

int main() {
  return 0;
}
