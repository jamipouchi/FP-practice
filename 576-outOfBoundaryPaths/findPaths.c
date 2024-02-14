#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int ***memoRec;

int **memoBotUp;

int findPathsRec(int m, int n, int maxMove, int startRow, int startColumn)
{
    if (startColumn < 0 || startColumn == n || startRow < 0 || startRow == m)
        return 1;
    if (maxMove == 0)
        return 0;
    else
    {
        if (memoRec[startRow][startColumn][maxMove] == -1)
            memoRec[startRow][startColumn][maxMove] = (((findPathsRec(m, n, maxMove - 1, startRow - 1, startColumn) +
                                                         findPathsRec(m, n, maxMove - 1, startRow, startColumn - 1)) %
                                                            MOD +
                                                        findPathsRec(m, n, maxMove - 1, startRow + 1, startColumn)) %
                                                           MOD +
                                                       findPathsRec(m, n, maxMove - 1, startRow, startColumn + 1)) %
                                                      MOD;
        return memoRec[startRow][startColumn][maxMove];
    }
}

int findPathsBottomUp(int m, int n, int maxMove, int startRow, int startColumn)
{
    for (int k = 0; k < maxMove; k++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Need to handle the case when the ball is at the edge of the grid. Pero em fa mandra.
                memoBotUp[i][j] = (((memoBotUp[i - 1][j] + memoBotUp[i][j - 1]) % MOD + memoBotUp[i + 1][j]) % MOD + memoBotUp[i][j + 1] % MOD);
            }
        }
    }
    return memoBotUp[startRow][startColumn];
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    memoRec = (int ***)malloc(sizeof(int **) * m);
    for (int i = 0; i < m; i++)
    {
        memoRec[i] = (int **)malloc(sizeof(int *) * n);
        for (int j = 0; j < n; j++)
        {
            memoRec[i][j] = (int *)malloc(sizeof(int) * (maxMove + 1));
            for (int k = 0; k <= maxMove; k++)
                memoRec[i][j][k] = -1;
        }
    }
    int ans = findPathsRec(m, n, maxMove, startRow, startColumn);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            free(memoRec[i][j]);
        free(memoRec[i]);
    }
    free(memoRec);

    memoBotUp = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        memoBotUp[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            memoBotUp[i][j] = 0;
    }
    ans = findPathsBottomUp(m, n, maxMove, startRow, startColumn);
    for (int i = 0; i < m; i++)
        free(memoBotUp[i]);
    free(memoBotUp);

    return ans;
}

int main()
{
    printf("%d\n", findPaths(2, 2, 2, 0, 0));
    printf("%d\n", findPaths(1, 3, 3, 0, 1));
    return 0;
}