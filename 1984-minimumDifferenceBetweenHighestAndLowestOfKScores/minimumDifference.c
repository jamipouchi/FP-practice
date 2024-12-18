#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* left, const void* right) {
    return  *(int*)(right) - *(int*)(left);
}

int minimumDifference(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int minDiff = INT_MAX;
    for (int i = 0; i < numsSize - (k-1) ; i++) {
        int possibleMin = nums[i] - nums[i + (k-1)];
        minDiff = minDiff > possibleMin ? possibleMin : minDiff;
    }
    return minDiff;
}

int main() {
    int arr1[] = {90};
    int res1 = minimumDifference(arr1, 1, 1);
    if (res1 != 0) {
        printf("Test case 1 failed. Should be 0, but is: %d\n", res1);
        exit(EXIT_FAILURE);
    }
    int arr2[] = {9,4,1,7};
    int res2 = minimumDifference(arr2, 4, 2);
    if (res2 != 2) {
        printf("Test case 2 failed. Should be 2, but is: %d\n", res1);
        exit(EXIT_FAILURE);
    }
    printf("All test cases successful!\n");
}
