fun main(args: Array<String>) {
    val sol = Solution()
    assert(sol.minTaps(5, intArrayOf(3,4,1,1,0,0)) == 1)
    assert(sol.minTaps(3, intArrayOf(0,0,0,0)) == -1)
}

class Solution {
    fun minTaps(n: Int, ranges: IntArray): Int {
        val rangePairs = ranges.mapIndexed { index, range -> Pair(index - range, index + range) }.sortedBy { it.first }
        var idx = 0
        var taps = 0
        while (idx < n) {
            val (taken, rangePairs) = rangePairs.takeAndDropBy { it.first <= idx }
            if (taken.size == 0) {
                return -1
            }
            val nextIdx = taken.maxBy { it.second }.second
            if (nextIdx == idx) {
                return -1
            }
            idx = nextIdx
            taps++
        }
        return taps
    }

    fun <T> List<T>.takeAndDropBy(pred: (T) -> Boolean) : Pair<List<T>,List<T>> {
        val taken = this.takeWhile(pred)
        return Pair(taken, this.drop(taken.size))
    }
}