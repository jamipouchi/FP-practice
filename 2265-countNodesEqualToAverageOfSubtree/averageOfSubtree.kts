class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    fun averageOfSubtree(root: TreeNode?): Int {
        res = 0
        visitNode(root!!)
        return res
    }

    private fun visitNode(node: TreeNode): Int {
        var nodes = 1
        val nodeVal = node.`val`
        node.left?.run {
            nodes += visitNode(this)
            node.`val` += `val`
        }
        node.right?.run {
            nodes += visitNode(this)
            node.`val` += `val`
        }
        if (nodeVal == node.`val` / nodes) {
            res++
        }
        return nodes
    }

    private var res = 0
}