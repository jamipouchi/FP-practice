#include <stdlib.h>
#include <string.h>

struct CumSum {
  int cost;
  int balls;
};
// This is not needed. We can directly allocate an int*, and balls can be an int acting as a counter.
// Also, right could right on top of left being the result itself, but who cares, both left and right live in the stack.

int *minOperations(char *boxes, int *returnSize) {
  int numBoxes = strlen(boxes);

  struct CumSum left[numBoxes];
  left[0] = (struct CumSum){
      .cost = 0,
      .balls = boxes[0] == '1' ? 1 : 0,
  };
  for (int i = 1; i < numBoxes; i++) {
    left[i] = (struct CumSum){
        .cost = left[i - 1].cost + left[i - 1].balls,
        .balls = left[i - 1].balls + (boxes[i] == '1' ? 1 : 0),
    };
  }

  struct CumSum right[numBoxes];
  right[numBoxes - 1] = (struct CumSum){
      .cost = 0,
      .balls = boxes[numBoxes - 1] == '1' ? 1 : 0,
  };
  for (int i = numBoxes - 2; i >= 0; i--) {
    right[i] = (struct CumSum){
        .cost = right[i + 1].cost + right[i + 1].balls,
        .balls = right[i + 1].balls + (boxes[i] == '1' ? 1 : 0),
    };
  }

  int *result = calloc(numBoxes, sizeof(struct CumSum));

  result[0] = right[0].cost;
  result[numBoxes - 1] = left[numBoxes - 1].cost;
  for (int i = 1; i < numBoxes - 1; i++) {
    result[i] = left[i].cost+right[i].cost;
  }
  *returnSize = numBoxes;
  return result;
}
