int waysToSplitArray(int* nums, int numsSize) {
    long cumSum[numsSize];
    cumSum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        cumSum[i] = cumSum[i-1] + nums[i];
    }
    int ways = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (cumSum[i] >= cumSum[numsSize-1] - cumSum[i]) {
            ways++;
        }
    }
    return ways;
}
