#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxFrequencyElements(std::vector<int> &nums) {
    std::unordered_map<int, int> freqs;

    for (int num : nums) {
      freqs[num]++;
    }
    int max_freq = 0;
    for (const auto &[_, freq] : freqs) {
      max_freq = std::max(freq, max_freq);
    }

    int count = 0;
    for (const auto &[_, freq] : freqs) {
      if (freq == max_freq) {
        count += freq;
      }
    }
    return count;
  }
};
