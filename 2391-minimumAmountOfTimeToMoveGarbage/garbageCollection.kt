class Solution {
    private val letters = listOf('M', 'P', 'G')
    fun garbageCollection(garbage: Array<String>, travel: IntArray): Int {
        var travel = intArrayOf(0, *travel)
        var totalCost = 0
        letters.forEach { letter ->
            var found = false
            totalCost += garbage.foldRightIndexed(0) { idx, can,  acc ->
                when (val hits = can.count {it == letter}){
                    0 -> if (found) acc + travel[idx] else acc
                    else -> {
                        if (!found) {
                            found = true
                        }
                        acc + travel[idx] + hits
                    }
                }
            }
        }
       return totalCost 
    }
}