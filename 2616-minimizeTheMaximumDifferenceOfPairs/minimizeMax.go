package minimizemax

import "sort"

func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	var checkDiff func(int) bool
	checkDiff = func(maxDiff int) bool {
		pairs := 0
		for i := 0; i < len(nums)-1; i++ {
			if nums[i+1]-nums[i] <= maxDiff {
				pairs++
				i++
			}
		}
		return pairs >= p
	}
	l, r := 0, nums[len(nums)-1]-nums[0]
	for l <= r {
		m := (l + r) / 2
		if checkDiff(m) {
			r = m
		} else {
			l = m + 1
		}
	}
	return l
}
