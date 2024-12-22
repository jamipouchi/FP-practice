#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *buildArray(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *ret = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    ret[i] = nums[nums[i]];
  }
  return ret;
}
