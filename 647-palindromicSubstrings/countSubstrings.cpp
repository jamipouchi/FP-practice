#include <string>

class Solution
{
private:
    int countPalindromes(std::string s, int left, int right)
    {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(std::string s)
    {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += countPalindromes(s, i, i);     // odd
            count += countPalindromes(s, i, i + 1); // even
        }
        return count;
    }
};
