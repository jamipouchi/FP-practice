// I know it can be done using last result, I just like the clean (0..n).map(::bits)
class Solution {
    fun countBits(n: Int): IntArray {
        return (0..n).map(::bits).toIntArray()
    }
    private fun bits(n: Int): Int {
        var bits = 0;
        var x = n
        while (x != 0) {
            x = x and (x-1)
            bits++
        }
        return bits
    }
}