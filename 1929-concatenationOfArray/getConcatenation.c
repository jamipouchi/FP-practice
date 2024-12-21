#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* biggerNums = realloc(nums, 2 * numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        biggerNums[i+numsSize] = nums[i];
    }
    return biggerNums;
}
