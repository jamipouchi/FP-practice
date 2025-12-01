package main

import "slices"

func maxRunTime(n int, batteries []int) int64 {
	if len(batteries) < n {
		return 0
	}
	slices.Sort(batteries)
	if len(batteries) == n {
		return int64(batteries[0])
	}
	firstValidIndex := len(batteries) - n
	var extraCapacity int
	for i := range firstValidIndex {
		extraCapacity += batteries[i]
	}
	if n == 1 {
		return int64(batteries[firstValidIndex] + extraCapacity)
	}
	// We need to distribute the extraCapacity evenly among the n computers
	// we add until it tips, then we swap,and we repeat.
	aligned := 1
	for extraCapacity > 0 {
		diff := batteries[firstValidIndex+aligned] - batteries[firstValidIndex]
		if diff*aligned > extraCapacity {
			return int64(batteries[firstValidIndex] + extraCapacity/aligned)
		}
		for i := range aligned {
			batteries[firstValidIndex+aligned-1-i] += min(diff, extraCapacity)
			extraCapacity -= min(diff, extraCapacity)
		}
		if aligned < n-1 {
			aligned++
		} else {
			return int64(batteries[firstValidIndex] + extraCapacity/n)
		}
	}
	return int64(batteries[firstValidIndex])
}

/**
 * -
 * --
 * ---
 * ----
 * -----
 * ------
 */
