package main

func singleNumber(nums []int) []int {
	xor := 0 // This is the xor of the 2 numbers
	for _, num := range nums {
		xor ^= num
	}

	// Find the rightmost bit that is 1, as that bit must be different in the 2 numbers
	rightmostBit := xor & -xor

	// Divide the numbers into 2 groups, one with the rightmost bit 0, the other with the rightmost bit 1
	setBit := 0
	for _, num := range nums {
		if (num & rightmostBit) == 0 {
			setBit ^= num
		}
	}
	return []int{setBit, setBit ^ xor}
}
