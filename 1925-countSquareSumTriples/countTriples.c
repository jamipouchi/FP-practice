#include <math.h>

int triplesUpTo(int n) {
  int count = 0;
  for (int a = 1; a * a < n * n; a++) {
    for (int b = a + 1; b * b + a * a <= n * n; b++) {
      int c2 = a * a + b * b;
      int c = (int)(sqrt(c2) + 0.5);
      if (c <= n && c * c == c2) {
        count++;
      }
    }
  }
  return count;
}

int countTriples(int n) {
  // 2 * (a,b,c) triples, where a,b,c are unique, as (a,b,c) and (b,a,c) are the
  // same.
  return 2 * triplesUpTo(n);
}

// triples up to n?
// a = 1 => b = 2, 3, ... until a*a+b*b > n*n
// we can go until a = sqlt(n)
