#include <stdlib.h>

struct HeapElement {
  int value;
  int freq;
};

typedef struct {
  struct HeapElement *elements;
  int size;
  int capacity;
} Heap;

Heap heap_allocate(int capacity) {
  struct HeapElement *elements = malloc(sizeof(struct HeapElement) * capacity);
  return (Heap){elements, 0, capacity};
}

/**
 * A min-heap is a binary tree. (Ideas are for a min-heap, but we are building a
 * max-heap here!!) We represent it as an array (1-indexed). The left child is
 * at index 2*i, and the right child is at 2*i + 1.
 *       3
 *      /  \
 *     5    7
 *    / \  / \
 *   9 11 13 15
 *
 *   [3,5,7,9,11,13,15]
 *
 *
 * The way to add a value to the heap is to add it to the end of the array,
 * and then float it.
 *
 * For example, adding 4:
 *       3
 *      /  \
 *     5    7
 *    / \  / \
 *    9 11 13 15
 *   /
 *  4
 *  => float (twice in this case)
 *       3
 *      /  \
 *     4    7
 *    / \  / \
 *    5 11 13 15
 *   /
 *  9
 *  => [3,4,7,5,11,13,15,9]
 *
 *  Now adding 8:
 *        3
 *      /  \
 *     4    7
 *    / \  / \
 *    5 11 13 15
 *   / \
 *  9  8
 *  => does not need to float => This generates a wrong heap!! 9 > 8
 *
 *  Now adding 6:
 *        3
 *      /  \
 *     4    7
 *    / \  / \
 *    5 11 13 15
 *   / \6
 *  9  8
 *  => float (once)
 *        3
 *      /  \
 *     4    7
 *    / \  / \
 *    5 6 13 15
 *   / \11
 *  9  8
 *  => [3,4,7,5,6,13,15,9,8]
 */

int heap_sum_max_k(Heap heap, int k) {
  int sum = 0;
  while (k > 0 && heap.size > 0) {
    struct HeapElement maxElement = heap.elements[0];
    sum += maxElement.value;
    k--;
  }
}

void heap_float(Heap heap, int index) {
  if (index <= 1) {
    return;
  }
  struct HeapElement *elements = heap.elements;
  int freq = elements[index].freq;
  int parentIdx = index / 2;
  int parentFreq = elements[parentIdx].freq;
  if (freq > parentFreq) {
    struct HeapElement temp = elements[index];
    elements[index] = elements[parentIdx];
    elements[parentIdx] = temp;
    heap_float(heap, parentIdx);
  }
}

void heap_sink(Heap heap, int index) {
  struct HeapElement *elements = heap.elements;
  int freq = elements[index].freq;
  int leftIdx = index * 2;
  int rightIdx = index * 2 + 1;
  int largestIdx = index;

  if (leftIdx < heap.size && elements[leftIdx].freq > freq) {
    largestIdx = leftIdx;
  }
  if (rightIdx < heap.size &&
      elements[rightIdx].freq > elements[largestIdx].freq) {
    largestIdx = rightIdx;
  }
  if (largestIdx != index) {
    struct HeapElement temp = elements[index];
    elements[index] = elements[largestIdx];
    elements[largestIdx] = temp;
    heap_sink(heap, largestIdx);
  }
}

int heap_findIndex(Heap heap, int value) {
  for (int i = 0; i < heap.size; i++) {
    if (heap.elements[i].value == value) {
      return i;
    }
  }
  return -1;
}

void heap_add(Heap heap, int value) {
  int index = heap_findIndex(heap, value);
  if (index == -1) {
    // New element
    heap.elements[heap.size] = (struct HeapElement){.value = value, .freq = 1};
    heap_float(heap, heap.size);
    heap.size++;
  } else {
    // Existing element
    heap.elements[index].freq += 1;
    heap_float(heap, index);
  }
}

void heap_remove(Heap heap, int value) {
  int index = heap_findIndex(heap, value);
  if (index == -1) {
    return;
  }
  heap.elements[index].freq -= 1;
  heap_sink(heap, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findXSum(int *nums, int numsSize, int k, int x, int *returnSize) {}
