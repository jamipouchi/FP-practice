package reversebetween

type ListNode struct {
	Val  int
	Next *ListNode
}

// This is copied, but I like it :)
func reverseBetween(head *ListNode, left int, right int) *ListNode {
	if head == nil || left == right {
		return head
	}

	dummy := &ListNode{0, head}
	prev := dummy

	for i := 0; i < left-1; i++ {
		prev = prev.Next
	}

	current := prev.Next

	for i := 0; i < right-left; i++ {
		nextNode := current.Next
		current.Next = nextNode.Next
		nextNode.Next = prev.Next
		prev.Next = nextNode
	}

	return dummy.Next
}
