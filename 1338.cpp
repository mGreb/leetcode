/* 1338. Reduce Array Size to The Half
 * Medium
 * You are given an integer array arr.
 * You can choose a set of integers and remove
 * all the occurrences of these integers in the array.
 * Return the minimum size of the set so that
 * at least half of the integers of the array are removed.*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    static int minSetSize(const std::vector<int>& arr) {
        std::unordered_map<int, int> umap;
        for (auto item: arr)
            ++umap[item];
        
        std::vector<int> v;
        v.reserve(umap.size());
        for(const auto& item: umap)
            v.push_back(item.second);
        
        std::sort(v.begin(), v.end(), std::greater<int>());
        
        int acc = 0;
        for (size_t i = 0; i < v.size(); ++i) {
            acc += v[i];
            if (acc >= arr.size() / 2)
                return i + 1;
        }
        
        return 0;
    }
};

int main()
{
    std::vector<bool> res;
    res.push_back(Solution::minSetSize({3,3,3,3,5,5,5,2,2,7}) == 2);
    res.push_back(Solution::minSetSize({7,7,7,7,7,7}) == 1);
    return 0;
}