int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int calculateMinCapability(int* nums, int numsSize, int k, int dp[numsSize][k+1], int start) {
  if (dp[start][k] != 0) {
    return dp[start][k];
  }

  if (k == 1) {
    int minCapability = INT_MAX;
    for (int i = start; i < numsSize; i++) {
      minCapability = min(minCapability, nums[i]);
    }
    dp[start][k] = minCapability;
    return minCapability;
  }

  int minCapability = INT_MAX;
  for (int i = start; i < numsSize - 2; i++) {
    int capability = max(nums[i], calculateMinCapability(nums, numsSize, k-1, dp, i + 2));
    minCapability = min(minCapability, capability);
  }

  dp[start][k] = minCapability;
  return minCapability;
}

void print_dp(int m, int n, int dp[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
}

int minCapability(int* nums, int numsSize, int k) {
  int dp[numsSize][k+1];
  for (int i = 0; i < numsSize; i++) {
    for (int j = 0; j < k+1; j++) {
      dp[i][j] = 0;
    }
  }

  calculateMinCapability(nums, numsSize, k, dp, 0);
  print_dp(numsSize, k+1, dp);

  return dp[0][k];
}
