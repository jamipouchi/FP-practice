package lettercombinations

import (
	"fmt"
	"reflect"
	"sort"
	"strings"
	"testing"
)

func Test1(t *testing.T) {
	want := []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}
	got := letterCombinations("23")
	sort.Slice(want, func(i, j int) bool {
		return want[i] < want[j]
	})
	sort.Slice(got, func(i, j int) bool {
		return got[i] < got[j]
	})
	fmt.Println(strings.Join(got, ","))
	if !reflect.DeepEqual(want, got) {
		t.Errorf("got: %v, want: %v", got, want)
	}
}

func Test2(t *testing.T) {
	want := []string{}
	got := letterCombinations("")
	sort.Slice(want, func(i, j int) bool {
		return want[i] < want[j]
	})
	sort.Slice(got, func(i, j int) bool {
		return got[i] < got[j]
	})
	if !reflect.DeepEqual(want, got) {
		t.Errorf("got: %v, want: %v", got, want)
	}
}

func Test3(t *testing.T) {
	want := []string{"a", "b", "c"}
	got := letterCombinations("2")
	sort.Slice(want, func(i, j int) bool {
		return want[i] < want[j]
	})
	sort.Slice(got, func(i, j int) bool {
		return got[i] < got[j]
	})
	if !reflect.DeepEqual(want, got) {
		t.Errorf("got: %v, want: %v", got, want)
	}
}
