package search

func search(nums []int, target int) int {
	var searchRotated func(int, int) int
	searchRotated = func(l, r int) int {
		if l > r {
			return -1
		}
		m := (l+r) / 2
		if nums[m] == target {
			return m
		} else if nums[m] >= nums[l] {
			if target >= nums[l] && target < nums[m] {
				return searchRotated(l, m - 1)
			} else {
				return searchRotated(m + 1, r)
			}
		} else {
			if target <= nums[r] && target > nums[m] {
				return searchRotated(m + 1, r)
			} else {
				return searchRotated(l, m - 1)
			}
		}
	}
	return searchRotated(0, len(nums)-1)
}
