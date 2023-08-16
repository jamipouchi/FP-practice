package maxslidingwindow

func maxSlidingWindow(nums []int, k int) []int {
	res := []int{}
	// nums[Q[i]] > nums[Q[j]] <=> i < j
	Q := []int{}
	i := 0
	for ; i < k; i++ {
		for len(Q) > 0 && nums[i] >= nums[Q[len(Q)-1]] {
			Q = Q[:len(Q)-1]
		}
		Q = append(Q, i)
	}

	res = append(res, Q[0])

	for ; i < len(nums); i++ {
		if len(Q) > 0 && Q[0] == i-k {
			Q = Q[1:]
		}
		for len(Q) > 0 && nums[i] >= nums[Q[len(Q)-1]] {
			Q = Q[:len(Q)-1]
		}
		Q = append(Q, i)
		res = append(res, nums[Q[0]])
	}
	return res
}
