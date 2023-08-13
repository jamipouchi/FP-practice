package validpartition

import "testing"

func Test1(t *testing.T) {
	want := true
	got := validPartition([]int{4, 4, 4, 5, 6})
	if want != got {
		t.Error()
	}
}

func Test2(t *testing.T) {
	want := false
	got := validPartition([]int{1,1,1,2})
	if want != got {
		t.Error()
	}
}
