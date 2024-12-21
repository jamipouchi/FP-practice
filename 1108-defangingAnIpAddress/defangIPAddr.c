#include <stdlib.h>
#include <string.h>

// Not reallocing nor freeing address, making it responsability of the caller.
char *defangIPaddr(char *address) {
  size_t resultSize = sizeof(char) * (strlen(address) + 6);
  char *result = malloc(resultSize);
  int j = 0;
  for (int i = 0; j < resultSize; i++) {
      if (address[i] == '.') {
          result[j++] = '[';
          result[j++] = '.';
          result[j++] = ']';
      } else {
          result[j++] = address[i];
      }
  }
  return result;
}
