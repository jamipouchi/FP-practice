package wordbreak

import "testing"

func Test1(t *testing.T) {
	want := true
	got := wordBreak("leetcode", []string{"leet", "code"})
	if want != got {
		t.Error()
	}
}
func Test2(t *testing.T) {
	want := true
	got := wordBreak("applepenapple", []string{"apple", "pen"})
	if want != got {
		t.Error()
	}
}
func Test3(t *testing.T) {
	want := false
	got := wordBreak("catsandog", []string{"cats", "dog", "sand", "and", "cat"})
	if want != got {
		t.Error()
	}
}

func TestMytest(t *testing.T) {
	want := false
	got := wordBreak("holadeuhola", []string{"hola", "adeu", "la", "ola", "adeuho"})
	if want != got {
		t.Error()
	}
}
