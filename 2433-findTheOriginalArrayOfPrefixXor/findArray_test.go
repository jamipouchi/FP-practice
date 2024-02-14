package leetcode

import (
	"reflect"
	"testing"
)

func Test1(t *testing.T) {
	expected := []int{5, 7, 2, 3, 2}
	ans := findArray([]int{5, 2, 0, 3, 1})
	if !reflect.DeepEqual(expected, ans) {
		t.Errorf("Expected %v, got %v", expected, ans)
	}
}

func Test2(t *testing.T) {
	expected := []int{13}
	ans := findArray([]int{13})
	if !reflect.DeepEqual(expected, ans) {
		t.Errorf("Expected %v, got %v", expected, ans)
	}
}
