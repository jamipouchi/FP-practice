#include <vector>

class Solution
{
public:
    std::vector<int> rearrangeArray(std::vector<int> &nums)
    {
        std::vector<int> positives = std::vector<int>();
        std::vector<int> negatives = std::vector<int>();
        for (int num: nums) {
            if (num < 0) {
                negatives.push_back(num);
            } else {
                positives.push_back(num);
            }
        }
        std::vector<int> result = std::vector<int>(nums.size());
        for (int i = 0; i < nums.size()/2; i++) {
                result[2*i] = positives[i];
                result[2*i+1] = negatives[i];
        }
        return result;
    }
};
