class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

// Kotlin kinda sucks in making me assert this... 
class Solution {
    fun hasCycle(head: ListNode?): Boolean {
        if (head == null) {
            return false
        }
        var slow = head
        var fast = head
        while (fast!!.next != null && fast!!.next!!.next != null) {
            slow = slow!!.next
            fast = fast.next.next
            if (slow == fast) {
                return true
            }
        }
        return false
    }
}