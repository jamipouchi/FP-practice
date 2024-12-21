int finalValueAfterOperations(char **operations, int operationsSize) {
  int cum = 0;
  for (int i = 0; i < operationsSize; i++) {
    if (operations[i][1] == '+') {
      cum++;
    } else {
      cum--;
    }
  }
  return cum;
}
