#include "../uthash-master/src/uthash.h"

struct ListNode {
  int val;
  struct ListNode *next;
};

struct HashEntry {
  int key;
  void *_; // dummy value, as we only need a set. we will store NULL
  UT_hash_handle hh;
};

struct HashEntry *set = NULL;

int set_exists(int key) {
  struct HashEntry *find;
  HASH_FIND_INT(set, &key, find);
  return find != NULL;
}

void set_add(int key) {
  if (set_exists(key)) {
    return;
  }
  struct HashEntry *add;
  add = malloc(sizeof *add);
  add->key = key;
  HASH_ADD_INT(set, key, add);
}

struct ListNode *findNonExisting(struct ListNode *node) {
  while (node != NULL) {
    if (set_exists(node->val)) {
      node = node->next;
    } else {
      return node;
    }
  }
  return NULL;
}

struct ListNode *modifiedList(int *nums, int numsSize, struct ListNode *head) {
  for (int i = 0; i < numsSize; i++) {
    set_add(nums[i]);
  }

  struct ListNode *newHead = head;
  while (newHead != NULL) {
    if (set_exists(newHead->val)) {
      newHead = newHead->next;
    } else {
      break;
    }
  }

  struct ListNode *curr = newHead;
  while (curr != NULL) {
    curr->next = findNonExisting(curr->next);
    curr = curr->next;
  }

  HASH_CLEAR(hh, set);
  return newHead;
}
