#include "../uthash-master/src/uthash.h"

/**
 * I was unable to solve this. The solution is copied. My original solution is
 * commented below.
 *
 * I was naive, and forgot to consider numberOperations properly.
 */

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int leftBound(int *nums, int numsSize, int value) {
  int left = 0, right = numsSize - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] < value) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int rightBound(int *nums, int numsSize, int value) {
  int left = 0, right = numsSize - 1;
  while (left < right) {
    int mid = (left + right + 1) / 2;
    if (nums[mid] > value) {
      right = mid - 1;
    } else {
      left = mid;
    }
  }
  return left;
}

typedef struct {
  int key;
  int val;
  UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
  HashItem *pEntry = NULL;
  HASH_FIND_INT(*obj, &key, pEntry);
  return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
  if (hashFindItem(obj, key)) {
    return false;
  }
  HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
  pEntry->key = key;
  pEntry->val = val;
  HASH_ADD_INT(*obj, key, pEntry);
  return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
  HashItem *pEntry = hashFindItem(obj, key);
  if (!pEntry) {
    hashAddItem(obj, key, val);
  } else {
    pEntry->val = val;
  }
  return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
  HashItem *pEntry = hashFindItem(obj, key);
  if (!pEntry) {
    return defaultVal;
  }
  return pEntry->val;
}

void hashFree(HashItem **obj) {
  HashItem *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
}

int maxFrequency(int *nums, int numsSize, int k, int numOperations) {
  qsort(nums, numsSize, sizeof(int), compare);
  int ans = 0;
  HashItem *numCount = NULL;
  int lastNumIndex = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] != nums[lastNumIndex]) {
      hashSetItem(&numCount, nums[lastNumIndex], i - lastNumIndex);
      ans = fmax(ans, i - lastNumIndex);
      lastNumIndex = i;
    }
  }
  hashSetItem(&numCount, nums[lastNumIndex], numsSize - lastNumIndex);
  ans = fmax(ans, numsSize - lastNumIndex);
  for (int i = nums[0]; i <= nums[numsSize - 1]; i++) {
    int l = leftBound(nums, numsSize, i - k);
    int r = rightBound(nums, numsSize, i + k);
    int tempAns;
    if (hashFindItem(&numCount, i)) {
      tempAns = fmin(r - l + 1, hashGetItem(&numCount, i, 0) + numOperations);
    } else {
      tempAns = fmin(r - l + 1, numOperations);
    }
    ans = fmax(ans, tempAns);
  }
  hashFree(&numCount);
  return ans;
}

/* #include <stdio.h> */
/* #include <stdlib.h> */
/**/
/* int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
 */
/**/
/* int maxFrequency(int *nums, int numsSize, int k, int numOperations) { */
/*   qsort(nums, numsSize, sizeof(int), compare); */
/*   printf("Sorted array: \n"); */
/*   for (int i = 0; i < numsSize; i++) { */
/*     printf("%d ", nums[i]); */
/*   } */
/**/
/*   int minIndex = 0; */
/*   int maxFreq = 1; */
/**/
/*   for (int i = 1; i < numsSize; i++) { */
/**/
/*     int currMin; */
/*     if (numOperations > 0) { */
/*       currMin = nums[i] - k; */
/*     } else { */
/*       currMin = nums[i]; */
/*     } */
/*     for (int j = minIndex; j <= i; j++) { */
/*       int currMax; */
/*       if (j > i - numOperations) { */
/*         currMax = nums[j] + k; */
/*       } else { */
/*         currMax = nums[j]; */
/*       } */
/*       if (currMin <= currMax) { */
/*         minIndex = j; */
/*         break; */
/*       } */
/*     } */
/**/
/*     printf("\nIteration %d: minIndex = %d; currMin = %d, currMax = %d\n", i,
 */
/*            minIndex, nums[i] - k, nums[minIndex] + k); */
/*     maxFreq = (i - minIndex + 1) > maxFreq ? (i - minIndex + 1) : maxFreq; */
/*   } */
/**/
/*   return maxFreq; */
/* } */
/**/
/* // It's a problem of intersecting ranges */
/**/
/* // [{-1,1}, {3,5}, {4,6}] -> */
/* // {-1,1}, {3,5} -> 1 */
/* // {4,5} -> 2 */
/* // */
/* // {3,5}, {5,9}, {6,10} {7,11} => {7,9} */
/* // */
/* // (freq is just maxIndex - minIndex + 1) */
/* // and maxIndex is just i */
/* // and currMin is nums[i] - k */
/* // and currMax is nums[minIndex] + k */
/* // The only thing we need to keep track of is currMin, */
/* // 1. currMin = 3; currMax = 5, minIndex = 0, maxIndex = 0, freq = 1; */
/* // 2. currMin = 5; currMax = 5, minIndex = 0, maxIndex = 1, freq = 2; */
/* // 3. currMin = 6; currMax = 9, minIndex = 1, maxIndex = 2, freq = 2; */
/* // 4. currMin = 7; currMax = 9, minIndex = 1, maxIndex = 3, freq = 3; */
/**/
/* // A naive way, would be picking all possibilities of numOperations, */
/* // and then for each possibility, get min, max, and create a set with all */
/* // values in between */
/**/
/* // A better way is sorting the array, and picking a window of size */
/* // numOperations. In that case, could we compute range intersections */
/* // efficiently? I think so, because we know that the sequence is increasing
 */
/* // */
/* // 5 11 20 20 */
/* // Iteration 0: minIndex = 0; currMin = 5, currMax = 15 */
/* // Iteration 1: minIndex = 1; currMin = 6, currMax = 16 */
/* // Iteration 2: minIndex = 2; currMin = 15, currMax = 25 */
/* // Iteration 3: minIndex = 3; currMin = 15, currMax = 25 */
/* // */
/* // [11,47,71], k = 69, numOperations = 1 */
/* // Iteration 0: minIndex = 0; */
/* // Iteration 1: minIndex = 0; currMin = 47-69, currMax = 11 */
