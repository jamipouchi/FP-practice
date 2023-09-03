class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # m - 1 down, n - 1 right
        return math.comb(m+n-2, m-1)
        # return math.comb(m+n-2, n-1)