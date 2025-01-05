#include <stdlib.h>
#include <string.h>

char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int sLen = strlen(s);
    int* index = calloc(sLen + 1, sizeof(int));
    for (int i = 0; i < shiftsSize; i++) {
        char dir = shifts[i][2] ? 1 : -1;
        index[shifts[i][0]] += dir;
        index[shifts[i][1] + 1] -= dir;
    }
    int shift = 0;
    for (int i = 0; i < sLen; i++) {
        shift += index[i];
        int bump = (shift % 26 + 26) % 26;
        s[i] = 'a' + (s[i] - 'a' + bump) % 26;
    }
    return s;
}
