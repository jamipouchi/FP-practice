#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *largestValues(struct TreeNode *root, int *returnSize) {
  if (root == NULL) {
    *returnSize = 0;
    return NULL;
  }
  int* result = malloc(20*sizeof(int));
  int row = 1;
  result[0] = root->val;
  struct TreeNode* currRow[row];
  currRow[0] = root;
  while (1) {
      int numNodes = 1 << row;
      int maxNum = INT_MIN;
      struct TreeNode* nextRow[numNodes]; // 2^row (1-indexed)
      for (int i = 0; i < numNodes; i++) {
      }
  }
}

// Em fa tot el pal acabar-ho
