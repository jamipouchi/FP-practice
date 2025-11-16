#include <string.h>
#define MOD 1000000007

int numSub(char *s) {
  int len = strlen(s);
  int l = 0, r = 0;
  long long res = 0;
  while (r < len) {
    while (s[l] == '0') {
      l++;
      r++;
    }
    while (s[r] == '1') {
      r++;
    }
    res += ((long long)(r - l) * (r - l + 1) / 2) % MOD;
    r++;
    l = r;
  }
  return res;
}
