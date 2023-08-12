class Solution {
    fun uniquePathsWithObstacles(obstacleGrid: Array<IntArray>): Int {
        val m = obstacleGrid.size
        val n = obstacleGrid[0].size
        val memo = Array(m) { IntArray(n) }
        memo[0][0] = 1
        for (i in 0 until m) {
            for (j in 0 until n) {
                if (obstacleGrid[i][j] == 1) {
                    memo[i][j] = 0
                    continue
                }
                if (i > 0) memo[i][j] += memo[i - 1][j]
                if (j > 0) memo[i][j] += memo[i][j - 1]
            }
        }
        return memo[m - 1][n - 1]
    }
}

// memo[i][j] = memo[i - 1][j] + memo[i][j - 1]