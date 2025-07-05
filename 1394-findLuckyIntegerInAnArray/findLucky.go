package main

func findLucky(arr []int) int {
	var mapCount = make(map[int]int)

	for _, val := range arr {
		mapCount[val] += 1
	}

	highest := -1

	for k, f := range mapCount {
		if k == f && k > highest {
			highest = k
		}
	}

	return highest
}
