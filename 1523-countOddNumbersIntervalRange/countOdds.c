int countOdds(int low, int high) {
  // The number of odd numbers between low and high (inclusive)
  // 1 .. 5 => 3 (1, 3, 5):  (5 - 1)/2 + 1 = 3
  // 2 .. 5 => 2 (3, 5):  (5 - 2)/2 + 1 = 2
  // 2 .. 4 => 1 (3):  (4 - 2)/2 + 0 = 1
  //
  // odd * odd = odd
  // odd * even = even
  // even * even = even
  int parity = (low % 2) || (high % 2);
  return (high - low) / 2 + parity;
}
