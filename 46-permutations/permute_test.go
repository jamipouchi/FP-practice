package permute

import (
"testing"
"reflect"
)

func Test1(t *testing.T) {
	want := [][]int{{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}
	got := permute([]int{1, 2, 3})
	if !reflect.DeepEqual(want, got) {
		t.Errorf("want: %v != got: %v", want, got)
	}
}

func Test2(t *testing.T) {
	want := [][]int{{0,1},{1,0}}
	got := permute([]int{0,1})
	if !reflect.DeepEqual(want, got) {
		t.Errorf("want: %v != got: %v", want, got)
	}
}

func Test3(t *testing.T) {
	want := [][]int{{1}}
	got := permute([]int{1})
	if !reflect.DeepEqual(want, got) {
		t.Errorf("want: %v != got: %v", want, got)
	}
}