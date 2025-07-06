package main

type FindSumPairs struct {
	nums1 []int
	nums2 []int
	hm2   map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	hm2 := make(map[int]int)
	for _, val := range nums2 {
		hm2[val]++
	}
	return FindSumPairs{
		nums1: nums1,
		hm2:   hm2,
		nums2: nums2,
	}
}

// Adds val to nums2[index], i.e., apply nums2[index] += val.
func (this *FindSumPairs) Add(index int, val int) {
	toDecrease := this.nums2[index]
	this.hm2[toDecrease]--
	this.nums2[index] += val
	this.hm2[this.nums2[index]]++
}

// int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
func (this *FindSumPairs) Count(tot int) int {
	count := 0
	for _, v := range this.nums1 {
		count += this.hm2[tot-v]
	}
	return count
}
