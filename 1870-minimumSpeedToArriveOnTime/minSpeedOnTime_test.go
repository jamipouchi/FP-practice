package minimumspeedtoarriveontime

import "testing"

func Test1(t *testing.T) {
	dist := []int{1, 3, 2}
	hour := 6.
	want := 1
	got := minSpeedOnTime(dist, hour)
	if want != got {
		t.Errorf("got %d, wanted %d", got, want)
	}
}

func Test2(t *testing.T) {
	dist := []int{1, 3, 2}
	hour := 2.7
	want := 3
	got := minSpeedOnTime(dist, hour)
	if want != got {
		t.Errorf("got %d, wanted %d", got, want)
	}
}

func Test3(t *testing.T) {
	dist := []int{1, 3, 2}
	hour := 1.9
	want := -1
	got := minSpeedOnTime(dist, hour)
	if want != got {
		t.Errorf("got %d, wanted %d", got, want)
	}
}

func Test4(t *testing.T) {
	dist := []int{1, 1, 100000}
	hour := 2.01
	want := 10000000
	got := minSpeedOnTime(dist, hour)
	if want != got {
		t.Errorf("got %d, wanted %d", got, want)
	}
}
