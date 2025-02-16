#include <stdio.h>
#include <stdlib.h>

// impar:
// 7 5 3 1 6 3 5 7 4 2 6 2 4
// (n) (n-2) .. 1 (n-1) (3) .. (n-2) (n) (n-3) (n-5) .. 2 (n-1) 2 .. (n-3)

// par:
// 4 2 3 2 4 3 1
// 2 1 2
// 6 4 2 5 2 4 6 3 5 1 3
// 8 6 4 2 7 2 4 6 8 5 3 7 1 3 5
// 10 8 6 4 2 9 2 4 6 8 10 7 5 3 9 1 3 5 7
// (n) (n-2) .. 2 (n-1) 2 ... (n-2) (n) (n-3) (n-5) .. (n-1) 1 3 .. (n-3)


// THERE'S NO SUCH SEQUENCE. IT WAS A BACKTRACKING PROBLEM. FK LEETCODE.

int *constructDistancedSequence(int n, int *returnSize) {
  int *result = calloc(n * 2 - 1, sizeof(int));
  *returnSize = n * 2 - 1;
  int i = 0;
  // we first push n, n-2, ...etc
  for (int c = n; c > 0; c -= 2) {
    printf("[%d] = %d\n", i, c);
    result[i] = c; // (n) (n-2) .. 2 ó 1
    result[i + c] = c;
    i++;
  }
  if (n == 1) {
    // 1
    return result;
  }
  printf("[%d] = %d\n", i, n - 1);
  result[i] = n - 1;
  if (n < 3) {
    // 2 1 2
    return result;
  }
  result[i + n - 1] = n - 1;

  // n (x) (x) n
  i = n + 1;

  for (int c = n - 3; c > 1; c -= 2) {
    printf("[%d] = %d\n", i, c);
    if (c != 1) {
      result[i] = c;
    }
    result[i + c] = c;
    i++;
  }

  return result;
}

// n, n-2, n-4...
// , n-1, n-3

// 4 2 1 2 4 3 3

int main() { constructDistancedSequence(2, NULL); }
