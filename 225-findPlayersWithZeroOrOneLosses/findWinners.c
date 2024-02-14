/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// This will never work, as player[i] can be greater than matchesSize.
int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));

    int *gamesLost = (int*)malloc(sizeof(int) * matchesSize); // We prob don't need all the slots
    for (int i = 0; i < matchesSize; i++) {
        gamesLost[i] = -1;
    }

    for (int i = 0; i < matchesSize; i++) {
        int winner = matches[i][0];
        int loser = matches[i][1];
        if (gamesLost[winner] == -1) {
            gamesLost[winner] = 0;
        }
        if (gamesLost[loser] == -1) {
            gamesLost[loser] = 1;
        } else {
            gamesLost[loser]++;
        }
    }
    int *winners = (int*)malloc(sizeof(int) * matchesSize);
    int *losers = (int*)malloc(sizeof(int) * matchesSize);
    int winnersSize = 0;
    int losersSize = 0;
    for (int i = 0; i < matchesSize; i++) {
        if (gamesLost[i] == 0) {
            winners[winnersSize++] = i;
        } else if (gamesLost[i] == 1) {
            losers[losersSize++] = i;
        }
    }

    (*returnColumnSizes)[0] = winnersSize;
    (*returnColumnSizes)[1] = losersSize;
    int** res = malloc(sizeof(int*) * 2);
    res[0] = winners;
    res[1] = losers;
    return res;
}