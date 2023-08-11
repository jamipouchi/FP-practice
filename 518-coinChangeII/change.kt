class Solution {
    fun change(amount: Int, coins: IntArray): Int {
        val memo = IntArray(amount + 1)
        memo[0] = 1	
        for (i in (coins.size - 1) downTo 0) {
            for (j in coins[i]..amount) { 
                memo[j] += memo[j - coins[i]]	
            } 
        }
        return memo[amount]
    }
}

