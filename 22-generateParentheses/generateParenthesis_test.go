package generateparenthesis

import (
	"reflect"
	"testing"
)

func Test1(t *testing.T) {
	want := []string{"((()))", "(()())", "(())()", "()(())", "()()()"}
	got := generateParenthesis(3)
	if !reflect.DeepEqual(want, got) {
		t.Errorf("Wanted: %v but got: %v", want, got)
	}
}

func Test2(t *testing.T) {
	want := []string{"()"}
	got := generateParenthesis(1)
	if !reflect.DeepEqual(want, got) {
		t.Errorf("Wanted: %v but got: %v", want, got)
	}
}
