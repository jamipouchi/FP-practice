#include <stdlib.h>
#include <string.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#define bool char
#define true 1
#define false 0

typedef struct {
  char has[100000];
} FindElements;

void initialize(int start, FindElements* fe, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    fe->has[start] = true;
    initialize(2 * start + 1, fe, root->left);
    initialize(2 * start + 2, fe, root->right);
}

FindElements *findElementsCreate(struct TreeNode *root) {
  FindElements *fe = malloc(sizeof(FindElements));
  memset(fe->has, 0, sizeof(fe->has));
  initialize(0, fe, root);
  return fe;
}

bool findElementsFind(FindElements *obj, int target) {
    return obj->has[target];
}

void findElementsFree(FindElements *obj) {
    free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);

 * findElementsFree(obj);
*/
