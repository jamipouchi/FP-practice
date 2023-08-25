package partition

type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	s := &ListNode{}
	be := &ListNode{}
	s_curr := s
	be_curr := be

	for head != nil {
		if head.Val < x { // attach to s list
			s_curr.Next = head
			s_curr = s_curr.Next
		} else { // attach to bigger-equal list
			be_curr.Next = head
			be_curr = be_curr.Next
		}
		head = head.Next
	}

	be_curr.Next = nil    // avoid loops
	s_curr.Next = be.Next // concat smaller with bigger

	return s.Next
}
