#include "uthash.h"

struct hash_entry {
  int diff;
  long long count;
  UT_hash_handle hh;
};

struct hash_entry *create_hash_entry(int diff, int count) {
  struct hash_entry *s = malloc(sizeof(struct hash_entry));
  s->count = count;
  s->diff = diff;
  return s;
}

long long countBadPairs(int *nums, int numsSize) {
  long long goodPairs = 0;

  struct hash_entry *counts = NULL;

  // Given i > j:
  // j - i = nums[j] - nums[i] => nums[j] - j = nums[i] - i
  //
  // For each i, goodPairs += diffs[nums[i] - i]
  //
  // badPairs = totalPairs - goodPairs = (n choose 2) - goodPairs = n(n-1)/2 -
  // goodPairs

  for (int i = 0; i < numsSize; i++) {
    struct hash_entry *s;
    int diff = nums[i] - i;
    HASH_FIND_INT(counts, &diff, s);

    if (s == NULL) {
      struct hash_entry* new_entry = create_hash_entry(diff, 1);
      HASH_ADD_INT(counts, diff, new_entry);
    } else {
      goodPairs += s->count;
      s->count++;
    }
  }
  long long result;
  if (numsSize % 2 == 0) {
      return (long long)(numsSize/2) * (numsSize-1) - goodPairs;
  } else {
      return (long long)((numsSize-1)/2) * numsSize - goodPairs;
  }
}
