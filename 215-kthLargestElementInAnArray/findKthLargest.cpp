#include <algorithm>
#include <vector>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k-1; i++) {
            std::pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};