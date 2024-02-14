// ans[0] = duplicate number
// ans[1] = missing number
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int *ans = calloc(2, sizeof(int));
    // I feel like there's some clever xor way to do it.. :)
    int overall_xor = 0;
    for (int i = 0; i < numsSize; i++)
    {
        // This will give us the xor of the duplicate and the missing number
        overall_xor ^= nums[i];
        overall_xor ^= (i + 1);
    }
    // We can extract the duplicate and missing number from the xor
    // We can do this by finding the rightmost set bit
    // This will be the rightmost set bit of the duplicate or missing number
    // We can then use this to split the numbers into two groups
    // One group will have the rightmost set bit set, the other will not
    // The duplicate and missing number will be in different groups
    // We can then xor all the numbers in each group to find the duplicate and missing number
    int rightmost_set_bit = overall_xor & ~(overall_xor - 1);
    int first = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] & rightmost_set_bit)
        {
            first ^= nums[i];
        }
        if ((i + 1) & rightmost_set_bit)
        {
            first ^= (i + 1);
        }
    }
    int second = overall_xor ^ first;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == first)
        {
            ans[0] = first;
            ans[1] = second;
            break;
        }
        else if (nums[i] == second)
        {
            ans[1] = first;
            ans[0] = second;
            break;
        }
    }
    *returnSize = 2;
    return ans;
}
