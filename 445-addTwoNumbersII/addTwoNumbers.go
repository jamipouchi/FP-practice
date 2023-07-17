package addtwonumbersii

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	S1 := []int{}
	S2 := []int{}
	toStack(l1, &S1)
	toStack(l2, &S2)
	nextVal := S1[len(S1)-1] + S2[len(S2)-1]
	next := &ListNode{nextVal % 10, nil}
	remainder := nextVal / 10
	S1 = S1[:len(S1)-1]
	S2 = S2[:len(S2)-1]
	for len(S1) > 0 && len(S2) > 0 {
		nextVal = S1[len(S1)-1] + S2[len(S2)-1] + remainder
		S1 = S1[:len(S1)-1]
		S2 = S2[:len(S2)-1]
		next = &ListNode{nextVal % 10, next}
		remainder = nextVal / 10
	}
	for len(S1) > 0 {
		nextVal = S1[len(S1)-1] + remainder
		next = &ListNode{nextVal % 10, next}
		S1 = S1[:len(S1)-1]
		remainder = nextVal / 10
	}
	for len(S2) > 0 {
		nextVal = S2[len(S2)-1] + remainder
		next = &ListNode{nextVal % 10, next}
		S2 = S2[:len(S2)-1]
		remainder = nextVal / 10
	}
	if remainder > 0 {
		next = &ListNode{remainder, next}
	}
	return next
}

func toStack(l *ListNode, S *[]int) {
	*S = append(*S, l.Val)
	l = l.Next
	for l != nil {
		*S = append(*S, l.Val)
		l = l.Next
	}
}
