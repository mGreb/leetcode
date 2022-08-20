#include <vector>

using namespace std;

class Solution {
  struct seq_data {
    void push(int item) {
      last = item;
      ++len;
    }
    int last = 0;
    int len = 0;
  };
public:
  static bool isPossible(const vector<int>& nums) {
    if (nums.size() < 3)
      return false;

    std::vector<seq_data> buckets;
    for (auto num : nums) {
      bool inserted = false;
      int fallback = -1;
      for (size_t j = 0; j < buckets.size(); ++j) {
        auto& b = buckets[j];
        if (num - b.last == 1) {
          if (b.len < 3) {
            b.push(num);
            inserted = true;
            break;
          }
          else
            fallback = j;
        }
      }
      if (!inserted) {
        if (fallback == -1)
          buckets.push_back({ num, 1 });
        else
          buckets[fallback].push(num);
      }
    }

    for (const auto& bucket : buckets)
      if (bucket.len < 3)
        return false;
    return true;
  }
};

int main() {
  std::vector<bool> res;
  res.push_back(Solution::isPossible({ 1,2,3,3,4,5 }) == true);
  return 0;
}
