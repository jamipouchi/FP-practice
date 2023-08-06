package nummusicplaylists

func numMusicPlaylists(n int, goal int, k int) int {
	// memo[totalSongs][uniqueSongs]
	const MOD = 1e9 + 7
	memo := make([][]int, n+1)
	for i := range memo {
		memo[i] = make([]int, goal+1)
		for j := range memo[i] {
			memo[i][j] = -1
		}
	}
	var countPlaylists func(int, int) int
	countPlaylists = func(i, j int) int {
		if i == 0 && j == 0 {
			return 1
		}
		if i == 0 || j == 0 {
			return 0
		}
		if memo[i][j] != -1 {
			return memo[i][j]
		}
		// using a new song
		memo[i][j] = (countPlaylists(i-1, j-1) * (n - j + 1)) % MOD
		// using an existing song.
		if j > k {
			memo[i][j] += (countPlaylists(i-1, j) * (j - k)) % MOD
		}
		return memo[i][j]
	}
	return countPlaylists(n, goal)
}
