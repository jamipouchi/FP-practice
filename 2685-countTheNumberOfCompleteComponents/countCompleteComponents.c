#include <stdlib.h>

struct adjListNode {
  int numNeighbors;
  int *neighbors;
  char seen;
};

char isConnectedComponent(struct adjListNode *adjList, int start, int n) {
  int numNodes = 0; // should be equivalent to queueEnd
  int expectedNumNeighbors = adjList[start].numNeighbors;

  int *queue = malloc(sizeof(int) * n);
  queue[0] = start;
  adjList[start].seen = 1;

  char weGood = 1;

  int queueEnd = 1;
  for (int queueStart = 0; queueStart < queueEnd; queueStart++) {
#define node adjList[queue[queueStart]]
    for (int i = 0; i < node.numNeighbors; i++) {
#define neighbor adjList[node.neighbors[i]]
      if (neighbor.seen) {
        continue;
      }
      if (neighbor.numNeighbors != expectedNumNeighbors) {
        weGood = 0;
      }
      neighbor.seen = 1;
      queue[queueEnd++] = node.neighbors[i];
    }
  }

  free(queue);

  // Here we know:
  // 1. Number of nodes in the cc := queueEnd
  // 2. Number of neighbors of each node in the cc := expectedNumNeighbors
  // If it is a complete component, then the number of edges for each node
  // should be n - 1 => expectedNumNeighbors = queueEnd - 1
  if (weGood && expectedNumNeighbors == queueEnd - 1) {
    return 1;
  }
  return 0;
}

int countCompleteComponents(int n, int **edges, int edgesSize,
                            int *edgesColSize) {
  struct adjListNode adjList[n];
  for (int i = 0; i < n; i++) {
    adjList[i].numNeighbors = 0;
    adjList[i].neighbors = malloc(sizeof(int) * n);
    adjList[i].seen = 0;
  }
  for (int i = 0; i < edgesSize; i++) {
    adjList[edges[i][0]].neighbors[adjList[edges[i][0]].numNeighbors++] =
        edges[i][1];
    adjList[edges[i][1]].neighbors[adjList[edges[i][1]].numNeighbors++] =
        edges[i][0];
  }

  int totalConnectedComponents = 0;
  for (int i = 0; i < n; i++) {
    if (adjList[i].seen) {
      continue;
    }
    if (isConnectedComponent(adjList, i, n)) {
      totalConnectedComponents++;
    }
  }
  return totalConnectedComponents;
}
