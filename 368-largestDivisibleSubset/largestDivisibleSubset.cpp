#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

class Solution
{
private:
    std::unordered_set<int> factors(int x)
    {
        std::unordered_set<int> result;
        for (int i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
            {
                result.insert(i);
            }
        }
        return result;
    }

public:
    std::vector<int> largestDivisibleSubset(std::vector<int> &nums)
    {
        std::unordered_map<int, std::vector<int>> primeToSeen;
        int ones = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                ones++;
            }
            else
                for (int factor : factors(num))
                {
                    if (primeToSeen.find(factor) == primeToSeen.end())
                    {
                        primeToSeen[factor] = std::vector<int>();
                    }
                    primeToSeen[factor].push_back(num);
                }
        }
        for (auto [key, value] : primeToSeen)
        {
            std::cout << key << " : ";
            for (int i : value)
            {
                std::cout << i << " ";
            }
        }
        auto biggest = std::max_element(primeToSeen.begin(), primeToSeen.end(), [](auto a, auto b)
                                        { return a.second.size() < b.second.size(); });
        for (int i = 0; i < ones; i++)
        {
            biggest->second.push_back(1);
        }
        return biggest->second;
    }
};