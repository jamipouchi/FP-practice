package main

import (
	"testing"
)

func TestNumRescueBoats(t *testing.T) {
	people := []int{3, 2, 2, 1}
	limit := 3
	expected := 3
	got := numRescueBoats(people, limit)
	if got != expected {
		t.Errorf("got: %v, expected: %v", got, expected)
	}
}
