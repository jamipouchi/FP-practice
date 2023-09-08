class Solution {
    fun generate(numRows: Int): List<List<Int>> {
        return pascalTriangle(numRows, listOf(listOf(1)))
    }
    tailrec fun pascalTriangle(remaining: Int, rows: List<List<Int>>): List<List<Int>> {
        val nextRow : List<Int> = listOf(1) + rows.last().zipWithNext { a, b -> a+b } + listOf(1)
        return if (remaining == 0) rows else pascalTriangle(remaining - 1, rows + listOf(nextRow))
    }
}