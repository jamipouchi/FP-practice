int rob(int *nums, int numsSize)
{
    int memo[numsSize + 1];
    memo[0] = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        // memo displaced one index from nums
        memo[i] = max(memo[i - 1], nums[i - 1] + (i - 2 >= 0 ? memo[i - 2] : 0));
    }
    return memo[numsSize];
}

// max (res[i-2] + nums[i], res[i-1])

int rob2(int *nums, int numsSize)
{
    int i_2 = 0, i_1 = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int tmp = i_1;
        i_1 = max(i_2 + nums[i], i_1);
        i_2 = tmp;
    }
    return i_1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
