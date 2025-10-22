/**
 * This was yesterday's comment:
 * I was unable to solve this. The solution is copied. My original solution is
 * commented below.
 *
 * I was naive, and forgot to consider numberOperations properly.
 *
 * Today, I saw that my idea wasn't so wrong. (I actually saw the solution
 * though, so no honor for me)
 */

#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int maxFrequency(int *nums, int numsSize, int k, int numOperations) {
  qsort(nums, numsSize, sizeof(int), compare);
  int maxFreq = 1;
  int cnt = 0;
  int left = 0, right = 0;
  // For 'exactly' a number, it can exceed numOperations
  // Here left and right pointers depend on the middle number
  for (int i = 0; i < numsSize; i++) {
    cnt += 1;
    if (i < numsSize - 1 && nums[i] == nums[i + 1]) {
      continue;
    }
    while (nums[left] + k < nums[i]) {
      left++;
    }
    while (right < numsSize && nums[right] - k <= nums[i]) {
      right++;
    }
    maxFreq = max(maxFreq, min(right - left, numOperations + cnt));
    cnt = 0;
  }
  if (maxFreq > numsSize) {
    return maxFreq;
  }
  // This is what I was missing. If it's not one of the numbers, for it to be a
  // window, we can simply consider the window size of 2k.
  // Here we only consider the distance between left and right pointers.
  left = 0;
  for (int right = 0; right < numsSize; right++) {
    while (nums[left] < nums[right] - 2 * k) {
      left++;
    }
    maxFreq = max(maxFreq, min(right - left + 1, numOperations));
  }
  return maxFreq;
}
