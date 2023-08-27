package isinterleave

import "testing"

func Test1(t *testing.T) {
	want := true
	got := isInterleave("aabcc", "dbbca", "aadbbcbcac")
	if want != got {
		t.Error()
	}
}

func Test2(t *testing.T) {
	want := false
	got := isInterleave("aabcc", "dbbca", "aadbbbaccc")
	if want != got {
		t.Error()
	}
}

func Test3(t *testing.T) {
	want := true
	got := isInterleave("", "", "")
	if want != got {
		t.Error()
	}
}