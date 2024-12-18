#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#define bool char
#define true 1
#define false 0

bool isLastLevel(struct TreeNode** ts, size_t numElements) {
    bool full = true;
    for (size_t i = 0; i < numElements ; i++) {
        if (!(ts[i] == NULL) && (ts[i]->left != NULL || ts[i]->right != NULL)) {
            return false;
        }
        if (full) {
            if (ts[i] == NULL) {
                full = false;
            }
        } else {
            if (!(ts[i] == NULL)) {
                return false;
            }
        }
    }
    return true;
}


bool areLeveled(struct TreeNode** ts, size_t numElements) {
    bool full = true;
    for (size_t i = 0; i < numElements; i++) {
        if (full) {
            if (ts[i] == NULL) {
                full = false;
            }
        } else {
            if (!(ts[i] == NULL)) {
                return false;
            }
        }
    }
    if (full) {
        struct TreeNode** childTs = malloc(2 * numElements * sizeof(struct TreeNode*));
        for (size_t i = 0; i < numElements; i++) {
            childTs[2*i] = ts[i]->left;
            childTs[2*i+1] = ts[i]->right;
        }
        return areLeveled(childTs, 2*numElements);
    } else {
        return isLastLevel(ts, numElements);
    }
}

bool isCompleteTree(struct TreeNode* root) {
    if (root == NULL) {
       return true;
    }
    struct TreeNode* ts[] = {root->left, root->right};
    return areLeveled(ts, 2);
}
