package permute

var permutations [][]int

func permute(nums []int) [][]int {
	permutations = make([][]int, 0)
	used := make([]bool, len(nums))
	buildPermutations(nums, used, &[]int{})
	return permutations
}

func buildPermutations(nums []int, used []bool, curr *[]int) {
	if len(*curr) == len(nums) {
		toAdd := make([]int, len(nums))
		copy(toAdd, *curr)
		permutations = append(permutations, toAdd)
		return
	}
	for i, num := range nums {
		if !used[i] {
			used[i] = true
			*curr = append(*curr, num)
			buildPermutations(nums, used, curr)
			*curr = (*curr)[:len(*curr)-1]
			used[i] = false
		}
	}
}
