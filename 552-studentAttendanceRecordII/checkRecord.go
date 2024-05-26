package main

// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award.
// The answer may be very large, so return it modulo 10^9 + 7.

const MOD = 1000000007

// We will use DP to solve this problem
// The cost is max(A) * max(L) * n = 2 * 3 * n = 6n => O(n)
func checkRecord(n int) int {
	var memo [][2][3]int
	for i := 0; i <= n; i++ {
		memo = append(memo, [2][3]int{{-1, -1, -1}, {-1, -1, -1}})
	}

	return checkRecordFrom(n, 0, 0, memo)
}

func checkRecordFrom(n, A, L int, memo [][2][3]int) int {
	if A == 2 || L == 3 {
		return 0
	}
	if n == 0 {
		return 1
	}
	if val := memo[n][A][L]; val != -1 {
		return val
	}
	nextAttending := checkRecordFrom(n-1, A, 0, memo)
	nextLate := checkRecordFrom(n-1, A, L+1, memo)
	nextAbsent := checkRecordFrom(n-1, A+1, 0, memo)
	memo[n][A][L] = ((nextAttending+nextLate)%MOD + nextAbsent) % MOD
	return memo[n][A][L]
}
