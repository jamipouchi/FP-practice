package main

import "math"

func getMinMax(array []int) (int, int) {
	min := array[0]
	max := array[0]
	for _, num := range array[1:] {
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}
	return min, max
}

func maxDistance(arrays [][]int) int {
	min := math.MaxInt
	sMin := math.MaxInt
	max := math.MinInt
	sMax := math.MinInt
	same := true
	for _, array := range arrays {
		iMin, iMax := getMinMax(array)
		switch {
		case iMin < min && iMax > max:
			min, sMin = iMin, min
			max, sMax = iMax, max
			same = true
		case iMin < min:
			min, sMin = iMin, min
			same = false
		case iMax > max:
			max, sMax = iMax, max
			same = false
		case iMin < sMin || iMax > sMax:
			if iMin < sMin {
				sMin = iMin
			}
			if iMax > sMax {
				sMax = iMax
			}
		}
	}
	if !same {
		return max - min
	} else {
		if max-sMin > sMax-min {
			return max - sMin
		} else {
			return sMax - min
		}
	}
}
