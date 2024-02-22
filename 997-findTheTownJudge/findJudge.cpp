#include <vector>

class Solution {
public:
  int findJudge(int n, std::vector<std::vector<int>> &trust) {
    std::vector<int> trustCount(n + 1, 0);
    for (auto pair : trust) {
      trustCount[pair[0]]--;
      trustCount[pair[1]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (trustCount[i] == n - 1) {
        return i;
      }
    }
    return -1;
  }
};
