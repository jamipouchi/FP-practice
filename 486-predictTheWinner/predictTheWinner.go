package predictthewinner

type Val struct {
	int
	bool
}

var memo [][]Val

func PredictTheWinner(nums []int) bool {
	memo = make([][]Val, len(nums))
	for i := range nums {
		memo[i] = make([]Val, len(nums))
	}
	return maxRec(nums, 0, len(nums)-1) >= 0
}

func maxRec(nums []int, left, right int) int {
	val := memo[left][right]
	if val.bool {
		return val.int
	}
	if left == right {
		memo[left][right] = Val{nums[left], true}
		return nums[left]
	}
	chooseL := nums[left] - maxRec(nums, left+1, right)
	chooseR := nums[right] - maxRec(nums, left, right-1)
	res := max(chooseL, chooseR)
	memo[left][right] = Val{res, true}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// BOTH PLAYERS PLAY PERFECTLY! so subtracting is not ok?!
