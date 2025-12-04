#include <string.h>
// we need to trim 'L' from the start and 'R' from the end'

int countCollisions(char *directions) {
  int l = 0;
  int r = strlen(directions) - 1;
  while (l <= r && directions[l] == 'L') {
    l++;
  }
  while (r >= l && directions[r] == 'R') {
    r--;
  }

  // we now know that directions[l..r] contains all collisions
  // we need to simply count of 'L' and 'R' in this range
  int collisions = 0;
  for (int i = l; i <= r; i++) {
    if (directions[i] != 'S') {
      collisions++;
    }
  }
  return collisions;
}
