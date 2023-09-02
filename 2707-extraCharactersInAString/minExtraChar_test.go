package minextrachar

import "testing"

func Test1(t *testing.T) {
	want := 1
	got := minExtraChar("leetscode", []string{"leet", "code", "leetcode"})
	if want != got {
		t.Errorf("Wanted: %v, got: %v", want, got)
	}
}

func Test2(t *testing.T) {
	want := 3
	got := minExtraChar("sayhelloworld", []string{"hello", "world"})
	if want != got {
		t.Errorf("Wanted: %v, got: %v", want, got)
	}
}
