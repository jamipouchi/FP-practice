/**
 * The idea is to go for a greedy approach. For n (n > 1) consecutive ballos of
 * the same color, keep the one with the maximum neededTime and remove the rest.
 *
 */
int minCost(char *colors, int *neededTime, int neededTimeSize) {
  int totalCost = 0;
  for (int i = 1; i < neededTimeSize; i++) {
    if (colors[i] == colors[i - 1]) {
      if (neededTime[i] < neededTime[i - 1]) {
        totalCost += neededTime[i];
        neededTime[i] = neededTime[i - 1];
      } else {
        totalCost += neededTime[i - 1];
      }
    }
  }
  return totalCost;
}
