package bestclosingtime

import "testing"

func Test1(t *testing.T) {
	want := 2
	got := bestClosingTime2("YYNY")
	if want != got {
		t.Errorf("wanted %d, got %d", want, got)
	}
}

func Test2(t *testing.T) {
	want := 0
	got := bestClosingTime2("NNNN")
	if want != got {
		t.Errorf("wanted %d, got %d", want, got)
	}
}

func Test3(t *testing.T) {
	want := 4
	got := bestClosingTime2("YYYY")
	if want != got {
		t.Errorf("wanted %d, got %d", want, got)
	}
}
