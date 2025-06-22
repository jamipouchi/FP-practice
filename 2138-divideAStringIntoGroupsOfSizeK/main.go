package main

func divideString(s string, k int, fill byte) []string {
	i := 0
	slots := (len(s) + k - 1) / k
	bytes := make([][]byte, slots)
	for j := range slots {
		bytes[j] = make([]byte, k)
	}
	for _, byte := range []byte(s) {
		x, y := i/k, i%k
		bytes[x][y] = byte
		i++
	}
	for j := i; j < slots*k; j++ {
		x, y := j/k, j%k
		bytes[x][y] = fill
	}
	ans := make([]string, slots)
	for i := range slots {
		ans[i] = string(bytes[i][:])
	}
	return ans
}
