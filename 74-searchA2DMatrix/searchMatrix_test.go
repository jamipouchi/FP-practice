package searchmatrix

import "testing"

func Test1(t *testing.T) {
	want := true
	got := searchMatrix([][]int{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3)
	if want != got {
		t.Error()
	}
}

func Test2(t *testing.T) {
	want := false
	got := searchMatrix([][]int{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13)
	if want != got {
		t.Error()
	}
}
