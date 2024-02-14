#include <string>
#include <unordered_map>

class Solution
{
private:
    std::string trim_left(std::string &s, std::unordered_map<char, int> &available, int origin, int index)
    {
        while (available.find(s[index]) == available.end() || --available[s[index]] >= 0)
        {
            index--;
        }
        return s.substr(origin, index);
    }
    std::string trim_right(std::string &s, std::unordered_map<char, int> &available, int index, int end)
    {
        while (available.find(s[index]) == available.end() || --available[s[index]] >= 0)
        {
            index++;
        }
        return s.substr(index, end);
    }
    std::string minWindow(std::string &s, std::unordered_map<char, int> &available, int left, int right)
    {
        while (left < right && available.find(s[left]) == available.end())
        {
            left++;
        }
        while (right > left && available.find(s[right]) == available.end())
        {
            right++;
        }
        if (left > right)
        {
            return "";
        }
        // The char in the left is in available, and the char in the right is in available.
        // Thus, we have 2 choices: remove from the left, or remove from the right. (If we have enough!)
        if (--available[s[left]] >= 0)
        {
            if (--available[s[right]] >= 0)
            {
                std::string l_string = minWindow(s, available, left + 1, right);
                std::string r_string = minWindow(s, available, left, right + 1);
                return l_string < r_string ? l_string : r_string;
            }
            else
            {
                return trim_left(s, available, left, right);
            }
        }
        else if (--available[s[right]] >= 0)
        {
            return trim_right(s, available, left, right);
        }
        return s.substr(left, right);
    }

public:
    std::string minWindow(std::string s, std::string t)
    {
        if (s.empty() || t.empty())
            return "";
        std::unordered_map<char, int> available;
        for (char c : s)
        {
            available[c]++;
        }
        for (char c : t)
        {
            available[c]--;
            if (available[c] < 0)
                return "";
        }

        int left = 0;
        int right = s.size() - 1;

        return minWindow(s, available, left, right);
    }
};

// Start with full string. Trim left right.
// When find a char that is needed, there is a bifurcation... This should be improved with DP.