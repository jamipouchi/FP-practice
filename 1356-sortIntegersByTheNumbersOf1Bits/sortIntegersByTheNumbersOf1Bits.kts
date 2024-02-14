import java.util.Comparator

class Solution {
    fun sortByBits(arr: IntArray): IntArray = arr.sortedWith(Comparator { left, right ->
        val leftBits = left.countOneBits()
        val rightBits = right.countOneBits()
        if (leftBits == rightBits) {
            left - right
        } else {
            leftBits - rightBits
        }
    }).toIntArray()
}