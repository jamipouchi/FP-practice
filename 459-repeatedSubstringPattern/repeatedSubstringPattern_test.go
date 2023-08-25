package repeatedsubstringpattern

import "testing"

func Test1(t *testing.T) {
	want := true
	got := repeatedSubstringPattern("abab")
	if want != got {
		t.Error()
	}
}

func Test2(t *testing.T) {
	want := false
	got := repeatedSubstringPattern("aba")
	if want != got {
		t.Error()
	}
}

func Test3(t *testing.T) {
	want := true
	got := repeatedSubstringPattern("abcabcabcabc")
	if want != got {
		t.Error()
	}
}

func Test4(t *testing.T) {
	want := false
	got := repeatedSubstringPattern("aabaaba")
	if want != got {
		t.Error()
	}
}
