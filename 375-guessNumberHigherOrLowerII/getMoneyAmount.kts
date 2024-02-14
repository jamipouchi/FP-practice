import kotlin.math.absoluteValue
import kotlin.math.max
import kotlin.math.min

// THIS CODE DOESN'T WORK. IT IS SAD.

class Solution {
    fun getMoneyAmount(n: Int): Int = numEqualAmountSplits(1..n)

    private fun numEqualAmountSplits(range: IntRange): Int {
        return when (range.numElems()) {
            1 -> 0
            2 -> range.first
            else -> {
                var split = getSplit(range)
                val lower = range.first..split - 1
                val upper = split + 1..range.last
                println("split: $split")
                println("lower: $lower")
                println("upper: $upper")
                split + max(numEqualAmountSplits(lower), numEqualAmountSplits(upper))
            }
        }
    }

    private fun getSplit(range: IntRange): Int = range.toList().binarySearch {
        amountInRange(range.first..it - 1) - amountInRange(min(range.last, it + 1)..range.last)
    }.absoluteValue

    private fun amountInRange(range: IntRange): Int = (range.first + range.last) * range.count() / 2

    private fun IntRange.numElems() = this.last - this.first + 1
}

// 1..10 -> 1..6, 8..10

var sol = Solution()
println("TXATXAN: ${sol.getMoneyAmount(10)}")