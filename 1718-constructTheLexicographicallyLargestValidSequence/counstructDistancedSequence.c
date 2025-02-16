#include <stdlib.h>

// ### After knowing it's a backtracking problem.
char backtrack(int *arr, char *used, int index, int size) {
  if (index == size * 2 - 1) {
    return 1;
  }
  if (arr[index] != 0) {
    return backtrack(arr, used, index + 1, size);
  }
  // for int i = size; i > 0; i--
  for (int i = size; i > 0; i--) {
    if (i == 1) {
      if (used[1]) {
        return 0;
      }
      arr[index] = i;
      used[1] = 1;
      if (backtrack(arr, used, index + 1, size)) {
        return 1;
      } else {
        arr[index] = 0;
        used[1] = 0;
        return 0;
      }
    } else {
      if (!used[i] && index + i < size * 2 - 1 && arr[index + i] == 0) {
        arr[index] = i, arr[index + i] = i;
        used[i] = 1;
        if (backtrack(arr, used, index + 1, size)) {
          return 1;
        } else {
          arr[index] = 0, arr[index + i] = 0;
          used[i] = 0;
        }
      }
    }
  }
  return 0; // unreachable.
}

int *constructDistancedSequence(int n, int *returnSize) {
  int *result = calloc(n * 2 - 1, sizeof(int));
  char *used = calloc(n + 1, sizeof(char));
  *returnSize = n * 2 - 1;
  backtrack(result, used, 0, n);
  return result;
}

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

// int *constructDistancedSequence(int n, int *returnSize) {
//   int *result = calloc(n * 2 - 1, sizeof(int));
//   *returnSize = n * 2 - 1;
//   int i = 0;
//   // we first push n, n-2, ...etc
//   for (int c = n; c > 0; c -= 2) {
//     printf("[%d] = %d\n", i, c);
//     result[i] = c; // (n) (n-2) .. 2 ó 1
//     result[i + c] = c;
//     i++;
//   }
//   if (n == 1) {
//     // 1
//     return result;
//   }
//   printf("[%d] = %d\n", i, n - 1);
//   result[i] = n - 1;
//   if (n < 3) {
//     // 2 1 2
//     return result;
//   }
//   result[i + n - 1] = n - 1;

//   // n (x) (x) n
//   i = n + 1;

//   for (int c = n - 3; c > 1; c -= 2) {
//     printf("[%d] = %d\n", i, c);
//     if (c != 1) {
//       result[i] = c;
//     }
//     result[i + c] = c;
//     i++;
//   }

//   return result;
// }

// n, n-2, n-4...
// , n-1, n-3

// 4 2 1 2 4 3 3
