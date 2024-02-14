#include <vector>
#define GROUP_SIZE 3

class Solution
{
private:
    bool checkGroupable(std::vector<int> &nums, int k)
    {
        if (nums.size() % GROUP_SIZE != 0)
        {
            return false;
        }
        for (int i = 0; i < nums.size() / GROUP_SIZE; i++)
        {
            if (nums[i * GROUP_SIZE + GROUP_SIZE - 1] - nums[i * GROUP_SIZE] > k)
            {
                return false;
            }
        }
        return true;
    }

public:
    std::vector<std::vector<int>> divideArray(std::vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        if (checkGroupable(nums, k))
        {
            for (int i = 0; i < nums.size() / GROUP_SIZE; i++)
            {
                std::vector<int> group(GROUP_SIZE);
                for (int j = 0; j < GROUP_SIZE; j++)
                {
                    group[j] = (nums[i * GROUP_SIZE + j]);
                }
                result.push_back(group);
            }
        }
        return result;
    }
};