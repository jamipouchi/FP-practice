#include <string.h>
#define bool char
#define true 1
#define false 0

bool hasSameDigits(char *s) {
  int len = strlen(s);
  char newS[len];
  strncpy(newS, s, len);
  // We always reduce len by 1
  while (len-- > 2) {
    for (int i = 0; i < len; ++i) {
      newS[i] = '0' + (((newS[i] - '0') + (newS[i + 1] - '0')) % 10);
    }
  }
  return newS[0] == newS[1];
}
