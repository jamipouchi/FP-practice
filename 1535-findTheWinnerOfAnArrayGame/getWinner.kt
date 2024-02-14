class Solution {
    fun getWinner(arr: IntArray, k: Int): Int {
        var winner = arr[0]
        var winCount = 0
        for (i in 1 until arr.size) {
            if (arr[i] > winner) {
                winner = arr[i]
                winCount = 0
            }
            winCount++
            if (winCount == k) {
                break
            }
        }
        return winner    
    }
}
