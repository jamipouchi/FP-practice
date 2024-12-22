#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;
    int* biggerNums = realloc(nums, *returnSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        biggerNums[i+numsSize] = biggerNums[i];
    }
    return biggerNums;
}
