package main

import (
	"slices"
)

const mod = 1000000007

func numSubseq(nums []int, target int) int {
	slices.Sort(nums)
	return count(target, nums)
}

func count(target int, nums []int) int {
	count := 0
	for i, j := 0, len(nums)-1; i <= j; {
		if nums[i]+nums[j] > target {
			j--
		} else {
			count += powerOf2(j-i) % mod
			i++
		}
	}
	return count % mod
}

var powerOf2Cache = make([]int, 100001)

func powerOf2(n int) int {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return 2
	}
	if powerOf2Cache[n] != 0 {
		return powerOf2Cache[n]
	}
	if n%2 == 0 {
		powerOf2Cache[n] = powerOf2(n/2) * powerOf2(n/2) % mod
	} else {
		powerOf2Cache[n] = powerOf2(n/2) * powerOf2(n/2) * 2 % mod
	}
	return powerOf2Cache[n]
}
