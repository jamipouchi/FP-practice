class Solution {
    fun getLastMoment(n: Int, left: IntArray, right: IntArray): Int =
            maxOf(left.maxOrNull() ?: 0, n - (right.minOrNull() ?: n))
}

fun main(args: Array<String>) {
    val sol = Solution()
    assert(sol.getLastMoment(4, intArrayOf(4, 3), intArrayOf(0, 1)) == 4)
    assert(sol.getLastMoment(7, IntArray(7) { it }, intArrayOf()) == 7)
    assert(sol.getLastMoment(7, intArrayOf(), IntArray(7) { it }) == 7)
}
