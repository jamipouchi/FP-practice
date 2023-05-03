package findDifference

func findDifference(nums1 []int, nums2 []int) [][]int {
	set1 := make(map[int]bool)
	for _, num := range nums1 {
		set1[num] = true
	}
	set2 := make(map[int]bool)
	for _, num := range nums2 {
		set2[num] = true
	}

	var result = make([][]int, 2)

	for num := range set1 {
		if _, ok := set2[num]; ok {
			delete(set2, num)
		} else {
			result[0] = append(result[0], num)
		}
	}
	println(set2)
	for num := range set2 {
		result[1] = append(result[1], num)
	}

	return result
}
