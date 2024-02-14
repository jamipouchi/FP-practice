#include <vector>
#include <iostream>

// Beautiful solution from MYSELF.
// It could be unrolled to not use recursion, but I think it is much more readable this way.
class Solution
{
private:
    std::vector<std::vector<std::vector<int>>> dp;
    int cherryPickup(std::vector<std::vector<int>> &grid, int i, int j, int k)
    {
        if (i == grid.size())
        {
            return 0;
        }
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        int result = 0;
        // Cases where robots cannot go into the same cell ####################################################################
        result = std::max(result, cherryPickup(grid, i + 1, j, k)); // Both robots go down
        if (j > 0)
        {
            result = std::max(result, cherryPickup(grid, i + 1, j - 1, k));     // First robot goes left
            result = std::max(result, cherryPickup(grid, i + 1, j - 1, k - 1)); // Both robots go left
        }
        if (k < grid[0].size() - 1)
        {
            result = std::max(result, cherryPickup(grid, i + 1, j, k + 1));     // Second robot goes right
            result = std::max(result, cherryPickup(grid, i + 1, j + 1, k + 1)); // Both robots go right
        }
        if (j > 0 && k < grid[0].size() - 1)
        {
            result = std::max(result, cherryPickup(grid, i + 1, j - 1, k + 1)); // First robot goes left, second robot goes right
        }
        // Cases where robots could go into the same cell ####################################################################
        if (k - j > 1)
        {
            result = std::max(result, cherryPickup(grid, i + 1, j + 1, k)); // First robot goes right
            result = std::max(result, cherryPickup(grid, i + 1, j, k - 1)); // Second robot goes left
        }
        if (k - j > 2)
        {
            result = std::max(result, cherryPickup(grid, i + 1, j + 1, k - 1)); // First robot goes right, second robot goes left
        }
        dp[i][j][k] = result + grid[i][j] + grid[i][k];
        return dp[i][j][k];
    }

public:
    int cherryPickup(std::vector<std::vector<int>> &grid)
    {
        dp = std::vector<std::vector<std::vector<int>>>(grid.size(),
                                                        std::vector<std::vector<int>>(grid[0].size(),
                                                                                      std::vector<int>(grid[0].size(), -1)));
        cherryPickup(grid, 0, 0, grid[0].size() - 1);
        return dp[0][0][grid[0].size() - 1];
    }
};

// I assume that robots will never collide with each other. I am not sure if this is a valid assumption.
// I will use dynamic programming to solve this problem.

// By assuming that they never collide, we can make them step at the same time.
// We can restrict them to go to the same cell at the same time.

// The recurrence will be:
/*
dp[i][j][k] = max(
    dp[i-1][j][k], // Both robots go down
    dp[i-1][j-1][k], // First robot goes right
    dp[i-1][j][k-1], // Second robot goes right
    dp[i-1][j-1][k-1], // Both robots go right
    dp[i-1][j+1][k], // First robot goes left
    dp[i-1][j][k+1], // Second robot goes left
    dp[i-1][j+1][k+1], // Both robots go left
    dp[i-1][j-1][k+1] // First robot goes right, second robot goes left
    dp[i-1][j+1][k-1] // First robot goes left, second robot goes right
    )
     + grid[i][j] + grid[i][k]
*/
