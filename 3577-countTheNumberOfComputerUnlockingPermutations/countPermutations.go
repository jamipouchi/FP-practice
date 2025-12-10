package main

const MOD = 1000000007

func permutations(n int) int {
	var ans int64 = 1
	for i := 2; i <= n; i++ {
		ans = (ans * int64(i)) % MOD
	}
	return int(ans)
}

func countPermutations(complexity []int) int {
	min := complexity[0]
	n := len(complexity)
	for i := 1; i < n; i++ {
		if complexity[i] < min {
			return 0
		}
	}
	return permutations(n - 1)
}

