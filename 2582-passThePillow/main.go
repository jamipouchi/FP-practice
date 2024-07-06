package main

func passThePillow(n int, time int) int {
	// 1 2 3 ... n
	// double it (-2):
	// 1 2 3 ... n n-1 ... 2
	// 1 2 3 4 3 2

	// 1 2 1

	// 1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2
	// 20 - 11 = 9
	// 20 - 12 = 8
	// 20 - 13 = 7
	//...

	pos := (time)%(2*n-2) + 1 // starts from 1

	if pos < n {
		return pos
	} else {
		return 2*n - pos
	}
}
