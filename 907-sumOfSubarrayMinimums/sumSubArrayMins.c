#define MOD 1000000007

int sumSubarrayMins(int *arr, int arrSize)
{
    int left[arrSize];
    int right[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[j] >= arr[i])
        {
            j = left[j];
        }
        left[i] = j;

        int k = arrSize - i - 1;
        j = k + 1;
        while (j < arrSize && arr[j] > arr[k])
        {
            j = right[j];
        }
        right[k] = j;
    }

    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum = (sum + (long)((arr[i] * (i - left[i]) % MOD) * (long)(right[i] - i)) % MOD) % MOD;
    }
    return sum;
}

// array[i] is the minimum for (i - left[i]) * (right[i] - i) subarrays
// This is because in an array of size (n with l elements on the left and r elements on the right), there are l * r subarrays that contain the middle element
// =>  It's all the combinations of l elements on the left and r elements on the right
// => On the left (l,  l - 1, ..., 1) => l combinations. And on the right (r, r - 1, ..., 1) => r combinations

// left[i] is the index of the first element that is smaller than array[i] on the left
// right[i] is the index of the first element that is smaller or equal than array[i] on the right
// The choice of the right being the first element that is smaller or equal is arbitrary, it could be reversed and it would still work

// left[i] = left[j] if arr[j] < arr[i] for all j < i
// right[i] = right[j] if arr[j] <= arr[i] for all j > i
