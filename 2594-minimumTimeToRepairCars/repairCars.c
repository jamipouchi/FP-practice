#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

struct Mechanic {
  int rank;
  int count;
  int carsRepaired;
};

struct Heap {
  struct Mechanic *heap;
  int size;
  // compare function should return 1 if first element is greater, else 0
  char (*compare)(struct Mechanic *, struct Mechanic *);
};

void swap(struct Heap *heap, int a, int b) {
  struct Mechanic temp = heap->heap[a];
  heap->heap[a] = heap->heap[b];
  heap->heap[b] = temp;
}

void sink(struct Heap *heap, int index) {
  int parent = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heap->size &&
      heap->compare(&heap->heap[left], &heap->heap[parent])) {
    parent = left;
  }

  if (right < heap->size &&
      heap->compare(&heap->heap[right], &heap->heap[parent])) {
    parent = right;
  }

  if (parent != index) {
    swap(heap, index, parent);
    sink(heap, parent);
  }
}

struct Heap *make_heap(struct Mechanic *arr, int arrSize,
                       char (*compare)(struct Mechanic *, struct Mechanic *)) {
  struct Heap *heap = malloc(sizeof(struct Heap));
  heap->heap = arr;
  heap->size = arrSize;
  heap->compare = compare;
  for (int i = arrSize / 2 - 1; i >= 0; i--) {
    sink(heap, i);
  }
  return heap;
}

char compare(struct Mechanic *a, struct Mechanic *b) {
  int aMinCarsRepaired = a->carsRepaired / a->count;
  int bMinCarsRepaired = b->carsRepaired / b->count;

  long long lCost = (long long)a->rank * (long long)aMinCarsRepaired *
                    (long long)aMinCarsRepaired;
  long long rCost = (long long)b->rank * (long long)bMinCarsRepaired *
                    (long long)bMinCarsRepaired;
  return lCost < rCost;
}

long long repairCars(int *ranks, int ranksSize, int cars) {

  int rankCounts[101] = {0};
  int uniqueRanks = 0;
  for (int i = 0; i < ranksSize; i++) {
    if (!rankCounts[ranks[i]]) {
      uniqueRanks++;
    }
    rankCounts[ranks[i]]++;
  }

  struct Mechanic mechanics[uniqueRanks];
  int j = 0;
  for (int i = 0; i < 101; i++) {
    if (rankCounts[i]) {
      struct Mechanic mechanic = {
          .rank = i, .count = rankCounts[i], .carsRepaired = rankCounts[i]};
      mechanics[j] = mechanic;
      j++;
    }
  }

  struct Heap *heap = make_heap(mechanics, uniqueRanks, compare);

  for (int i = 0; i < cars; i++) {
    heap->heap[0].carsRepaired++;
    sink(heap, 0);
  }

  long long maxCost = 0;
  for (int i = 0; i < heap->size; i++) {
    int carsRepaired = (heap->heap[i].carsRepaired - 1) / heap->heap[i].count;
    maxCost =
        max(maxCost, ((long long)heap->heap[i].rank) *
                         ((long long)carsRepaired) * ((long long)carsRepaired));
  }

  return maxCost;
}
