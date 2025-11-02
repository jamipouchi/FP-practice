#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MARK_GUARDED(grid, rr, c, guarded)                                     \
  do {                                                                         \
    if ((grid)[rr][c] != GUARDED) {                                            \
      (guarded)++;                                                             \
    }                                                                          \
    (grid)[rr][c] = GUARDED;                                                   \
  } while (0)

// 2 bits would be enough, but it's a bit harder to write, so we'll use a byte
typedef uint8_t CellType;
static const CellType EMPTY = 0;
static const CellType GUARD = 1;
static const CellType WALL = 2;
static const CellType GUARDED = 3;

int countUnguarded(int m, int n, int **guards, int guardsSize,
                   int *guardsColSize, int **walls, int wallsSize,
                   int *wallsColSize) {
  CellType grid[m][n];
  memset(grid, 0, sizeof(grid));
  for (int i = 0; i < guardsSize; i++) {
    grid[guards[i][0]][guards[i][1]] = GUARD;
  }
  for (int i = 0; i < wallsSize; i++) {
    grid[walls[i][0]][walls[i][1]] = WALL;
  }

  int guarded = 0;

  for (int i = 0; i < guardsSize; i++) {
    int r = guards[i][0];
    int c = guards[i][1];

    // Up
    for (int rr = r - 1; rr >= 0; rr--) {
      if (grid[rr][c] == WALL || grid[rr][c] == GUARD) {
        break;
      }
      MARK_GUARDED(grid, rr, c, guarded);
    }

    // Down
    for (int rr = r + 1; rr < m; rr++) {
      if (grid[rr][c] == WALL || grid[rr][c] == GUARD) {
        break;
      }
      MARK_GUARDED(grid, rr, c, guarded);
    }

    // Left
    for (int cc = c - 1; cc >= 0; cc--) {
      if (grid[r][cc] == WALL || grid[r][cc] == GUARD) {
        break;
      }
      MARK_GUARDED(grid, r, cc, guarded);
    }

    // Right
    for (int cc = c + 1; cc < n; cc++) {
      if (grid[r][cc] == WALL || grid[r][cc] == GUARD) {
        break;
      }
      MARK_GUARDED(grid, r, cc, guarded);
    }
  }

  int total = m * n;
  int unguarded = total - guarded - guardsSize - wallsSize;

  return unguarded;
}
