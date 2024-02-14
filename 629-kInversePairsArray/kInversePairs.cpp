#define MOD 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        std::vector<std::vector<int>> memo(n+1, std::vector<int>(k+1,0));
	for (int i = 0; i <= n; i++) {
		memo[i][0] = 1;
    	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			int ans = 0;
			for (int pos = 0; pos < min(i, j+1); pos++) {
				ans += memo[i-1][j-pos];
				ans %= MOD;
			}	
			memo[i][j] = ans;
		}
	}
	return memo[n][k];
    }
};
