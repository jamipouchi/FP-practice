package maximumnumberofeventsthatcanbeattendedii

import "sort"

func maxValue(events [][]int, k int) int {
	sort.Slice(events, func(i, j int) bool {
		return events[i][0] < events[j][0]
	})
	starts := make([]int, len(events))
	for i, start_end_value := range events {
		starts[i] = start_end_value[0]
	}
	next_indices := make([]int, len(events))
	for i := 0; i < len(events); i++ {
		next_indices[i] = bisect_right(starts, events[i][1])
	}
	dp := make([][]int, k)
	for i := 0; i < k; i++ {
		dp[i] = make([]int, len(events))
		for j := 0; j < len(events); j++ {
			dp[i][j] = -1
		}
	}

	var dfs func(int, int) int
	dfs = func(curr_idx, count int) int {
		if count == k || curr_idx == len(events) {
			return 0
		}
		if dp[count][curr_idx] != -1 {
			return dp[count][curr_idx]
		}
		next_idx := next_indices[curr_idx]
		dp[count][curr_idx] = max(dfs(curr_idx+1, count), events[curr_idx][2]+dfs(next_idx, count+1))
		return dp[count][curr_idx]
	}
	return dfs(0, 0)
}

func bisect_right(starts []int, end int) int {
	for idx, start := range starts {
		if start > end {
			return idx
		}
	}
	return len(starts)
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
