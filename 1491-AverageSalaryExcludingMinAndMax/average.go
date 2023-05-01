package average

func average(salary []int) float64 {
	min := salary[0]
	max := salary[0]
	sum := 0
	for _, s := range salary {
		if s < min {
			min = s
		}
		if s > max {
			max = s
		}
		sum += s
	}
	return float64(sum - min - max) / float64(len(salary) - 2)
}

/* func TestAverage(t *testing.T) {
	tests := []struct {
		salary []int
		want   float64
	}{
		{[]int{4000, 3000, 1000, 2000}, 2500.00000},
		{[]int{1000, 2000, 3000}, 2000.00000},
		{[]int{6000, 5000, 4000, 3000, 2000, 1000}, 3500.00000},
		{[]int{8000, 9000, 2000, 3000, 6000, 1000}, 4750.00000},
		{[]int{1000, 2000, 3000, 4000, 5000, 6000}, 3500.00000},
	}
	for _, tt := range tests {
		if got := average(tt.salary); got != tt.want {
			t.Errorf("average(%v) = %v, want %v", tt.salary, got, tt.want)
		}
	}
} */