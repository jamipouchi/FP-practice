#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    std::vector<bool> seen(nums.size() + 1, 0);
    for (int num : nums) {
      seen[num] = true;
    }
    for (int i = 0; i < seen.size(); i++) {
      if (!seen[i]) {
        return i;
      }
    }
    return -1;
  }
};
