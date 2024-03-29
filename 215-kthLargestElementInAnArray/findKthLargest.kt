class Solution {
    fun findKthLargest(nums: IntArray, k: Int): Int {
        // 1. choose a pivot.
        // 1. partition smaller than mid, bigger than mid.
        // 1. if bigger partition is bigger than k, repeat with bigger partition
        // 1. else if k falls in mid elements, return partition
        // 1. else if bigger partition + mid elements is smaller than k, call with smaller partition, k - size(smaller partition) - size (mid partition)
        val pivot = nums.random()
        val smaller = nums.filter {it < pivot}
        val bigger = nums.filter {it > pivot}
        val biggerSize = bigger.size
        val midSize = nums.size - smaller.size - biggerSize
        return if (k <= biggerSize) {
            findKthLargest(bigger.toIntArray(), k)
        } else if (k <= biggerSize + midSize) {
            pivot
        } else {
            findKthLargest(smaller.toIntArray(), k - biggerSize - midSize)
        }
    }
}
