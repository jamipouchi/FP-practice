class Solution {
    fun bestClosingTime(customers: String): Int {
        var curr = 0
        var min = 0
        var earliest = 0
        customers.forEachIndexed { i, c ->
            curr += if (c == 'N') 1 else -1
            if (curr < min) {
                min = curr
                earliest = i + 1
            }
        }        
        return earliest
    }
}