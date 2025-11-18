#define bool char
#define true 1
#define false 0

bool isOneBitCharacter(int *bits, int bitsSize) {
  int ptr = 0;
  while (ptr < bitsSize - 1) {
    if (bits[ptr] == 1) {
      ptr += 2;
    } else {
      ptr += 1;
    }
  }
  if (ptr == bitsSize) {
    return false;
  } else {
    return bits[bitsSize - 1] == 0;
  }
}
