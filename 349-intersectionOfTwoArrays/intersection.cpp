#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> intersection(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    std::set<int> s1(nums1.begin(), nums1.end());
    std::vector<int> res;
    for (int num : nums2) {
      if (s1.find(num) != s1.end()) {
        res.push_back(num);
        s1.erase(num);
      }
    }
    return res;
  }
};
