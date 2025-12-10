#define MOD 1000000007
#define bool char
#define true 1
#define false 0

inline bool possible(int base, int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] <= base) {
      return false;
    }
  }
  return true;
}

inline int permutations(int n) {
  // I's basically a factorial
  // n * n-1 * n-2...
  long long res = 1;
  for (int i = 2; i <= n; i++) {
    res = (res * i) % MOD;
  }
  return (int)res;
}

int countPermutations(int *complexity, int complexitySize) {
  if (possible(complexity[0], &complexity[1], complexitySize - 1)) {
    return permutations(complexitySize - 1);
  } else {
    return 0;
  }
}
