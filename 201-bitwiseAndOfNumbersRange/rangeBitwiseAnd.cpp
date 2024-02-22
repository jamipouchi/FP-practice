class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    int shift_count = 0;
    while (left != right) {
      left >>= 1;
      right >>= 1;
      shift_count++;
    }
    return left << shift_count;
  }
};

// Clean way to write the above solution:
// return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
// could also be written as (n == m) ? n : rangeBitwiseAnd(m/2, n/2) << 1;
