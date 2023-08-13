package validpartition

var impossible []bool

func validPartition(nums []int) bool {
	impossible = make([]bool, len(nums))
	return checkValidAt(0, nums)
}

func checkValidAt(idx int, nums []int) bool {
	if len(nums) == 0 {
		return true
	}
	if impossible[idx] {
		return false
	}
	// if memo[]. requires thinking global idx.
	if len(nums) >= 2 && areEqual(nums[0:2]...) {
		if checkValidAt(idx+2, nums[2:]) {
			return true
		}
	}
	if len(nums) >= 3 && (areEqual(nums[0:3]...) || areConsecutive(nums[0:3]...)) {
		if checkValidAt(idx+3, nums[3:]) {
			return true
		}
	}
	impossible[idx] = true
	return false
}

func areEqual(nums ...int) bool {
	first := nums[0]
	for _, num := range nums[1:] {
		if num != first {
			return false
		}
	}
	return true
}

func areConsecutive(nums ...int) bool {
	curr := nums[0]
	for _, num := range nums[1:] {
		if num-curr != 1 {
			return false
		}
		curr = num
	}
	return true
}
