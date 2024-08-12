package main

import (
	"math"
	"slices"
)

type KthLargest struct {
	nums []int
}

func Constructor(k int, nums []int) KthLargest {
	slices.SortFunc(nums, func(a, b int) int {
		return b - a
	})
	if len(nums) < k {
		toFill := k - len(nums)
		for i := 0; i < toFill; i++ {
			nums = append(nums, math.MinInt)
		}
	}
	return KthLargest{
		nums: nums[:k],
	}
}

func (this *KthLargest) Add(val int) int {
	k := len(this.nums) - 1
	if this.nums[k] >= val {
		// do nth
	} else {
		pos, _ := slices.BinarySearchFunc(this.nums, val, func(a, b int) int {
			if b > a {
				return 1
			} else {
				return -1
			} // To avoid overflow on a - b
		})
		this.nums = append(this.nums[:pos], append([]int{val}, this.nums[pos:k]...)...)
	}
	return this.nums[len(this.nums)-1]
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
