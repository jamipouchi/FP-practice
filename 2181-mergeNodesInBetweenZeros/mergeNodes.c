#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void printList(struct ListNode *head) {
  printf("[");
  char first = 1;
  while (head != NULL) {
    if (!first) {
      printf(",");
    } else {
      first = 0;
    }
    printf("%d", head->val);
    head = head->next;
  }
  printf("]\n");
}

struct ListNode *mergeNodes(struct ListNode *head) {
  // We are not freeing head. Assuming the caller does it.
  if (head == NULL) {
    return NULL;
  }
  head = head->next;
  // We will discard the first node of result. We are allocating one node too much, but makes the while loop easier.
  struct ListNode *resultHead = malloc(sizeof(struct ListNode));
  struct ListNode *next = resultHead;
  int cum = 0;
  while (head != NULL) {
    if (head->val == 0) {
      next->next = malloc(sizeof(struct ListNode));
      next->next->val = cum;
      cum = 0;
      next = next->next;
    } else {
      cum += head->val;
    }
    head = head->next;
  }
  struct ListNode *result = resultHead->next;
  free(resultHead);
  return result;
}

struct ListNode *new(int *nums, size_t numsSize) {
  struct ListNode *head = malloc(sizeof(struct ListNode));
  head->val = nums[0];
  struct ListNode *next = head;
  for (size_t i = 1; i < numsSize; i++) {
    next->next = malloc(sizeof(struct ListNode));
    next->next->val = nums[i];
    next = next->next;
  }
  return head;
}

int main() {
  int test1Nums[] = {0, 3, 1, 0, 4, 5, 2, 0};
  struct ListNode *test1 = new (test1Nums, 8);
  printList(test1);
  struct ListNode *res1 = mergeNodes(test1);
  printList(res1);

  int test2Nums[] = {0, 1, 0, 3, 0, 2, 2, 0};
  struct ListNode *test2 = new (test2Nums, 8);
  printList(test2);
  struct ListNode *res2 = mergeNodes(test2);
  printList(res2);
}
