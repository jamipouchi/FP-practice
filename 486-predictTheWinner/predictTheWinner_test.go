package predictthewinner

import "testing"

func Test1(t *testing.T) {
	nums := []int{1, 5, 2}
	expected := false
	got := PredictTheWinner(nums)
	if expected != got {
		t.Fatalf("Expected: %t, Got: %t", expected, got)
	}
}

func Test2(t *testing.T) {
	nums := []int{1, 5, 233, 7}
	expected := true
	got := PredictTheWinner(nums)
	if expected != got {
		t.Fatalf("Expected: %t, Got: %t", expected, got)
	}
}
