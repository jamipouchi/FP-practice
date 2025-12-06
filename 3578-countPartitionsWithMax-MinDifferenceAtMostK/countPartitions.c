#include <stdlib.h>

inline int numPartitions(int range) { return 1 << (range - 1); }

// This approach is wrong, it should find the 'min' numbers, and from there
// expand left to right.
//
// Also the direct sum is not true. Partitions(i,j) != Partitions(i,k) +
// Partitions(k+1,j)

int countPartitions(int *nums, int numsSize, int k) {
  int count = 0;
  int i = 0;
  while (i < numsSize) {
    int minIndex = i;
    int maxIndex = i;
    int j = i + 1;
    while (j < numsSize) {
      if (nums[j] < nums[minIndex]) {
        minIndex = j;
      } else if (nums[j] > maxIndex) {
        maxIndex = j;
      }
      if ((nums[maxIndex] - nums[minIndex]) > k) {
        break;
      }
      j++;
    }
    count += numPartitions(j - i);
    i = j;
  }
  return count;
}
// printf("i: %d, j: %d\n", i, j);

// For each number, see how many we can go to the right without exceeding k
// Given a range (l,r); there is
// It seems like they follow the pattern of powers of 2
// [1] = 1
// [1,2] => [1] [2] | [1,2] = 2
// [1,2,3] => [1] [2] [3] | [1,2] [3] | [1] [2,3] | [1,2,3] = 4
// [1,2,3,4] => [1] [2] [3] [4] | [1,2] [3] [4] | [1] [2,3] [4] | [1] [2]
// [3,4] | [1,2,3] [4] | [1,2] [3,4] | [1] [2,3,4] | [1,2,3,4] = 8
// [1,2,3,4,5] => [1] [2] [3] [4] [5] | [1,2] [3] [4] [5] | [1] [2,3] [4] [5]
// | [1] [2] [3,4] [5] | [1] [2] [3] [4,5] | [1,2,3] [4] [5] | [1,2] [3,4] [5]
// | [1,2] [3] [4,5] | [1] [2,3,4] [5] | [1] [2,3] [4,5] | [1] [2] [3,4,5] |
// [1,2,3,4] [5] | [1,2,3] [4,5] | [1,2] [3,4,5] | [1,2,3,4,5] = 16
//
// Yup, was right. Can be proved by induction, but a good way to see it (thx
// ChatGPT) is by having the choice of 'cutting' at any of the middle
// positions or not: 2^(n-1)
