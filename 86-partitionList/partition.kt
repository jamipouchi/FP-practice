class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun partition(head: ListNode?, x: Int): ListNode? {
        val s = ListNode()
        var s_curr = s
        val be = ListNode()
        var be_curr = be
        head.forEach {node -> if (node.`val` < x) {
                    s_curr.next = node 
                    s_curr = s_curr.next
                } else {
                    be_curr.next = node
                    be_curr = be_curr.next
                }
            }
        be_curr.next = null
        s_curr.next = be.next
        return s.next
    }
    fun ListNode?.forEach(f: (ListNode) -> Unit) {
        if (this == null) {
            return
        }
        f(this)
        this.next.forEach(f)
    }
}