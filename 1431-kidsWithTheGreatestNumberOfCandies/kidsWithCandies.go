func kidsWithCandies(candies []int, extraCandies int) []bool {
	max := 0
	for _, v := range candies {
		if v > max {
			max = v
		}
	}
	res := make([]bool, len(candies))
	for i, v := range candies {
		res[i] = v+extraCandies >= max
	}
	return res
}

// tests

func TestKidsWithCandies(t *testing.T) {
	candies := []int{2, 3, 5, 1, 3}
	extraCandies := 3
	expected := []bool{true, true, true, false, true}
	result := kidsWithCandies(candies, extraCandies)
	if !reflect.DeepEqual(result, expected) {
		t.Errorf("kidsWithCandies(%v, %d) = %v; expected %v", candies, extraCandies, result, expected)
	}
}

func TestKidsWithCandies2(t *testing.T) {
	candies := []int{4, 2, 1, 1, 2}
	extraCandies := 1
	expected := []bool{true, false, false, false, false}
	result := kidsWithCandies(candies, extraCandies)
	if !reflect.DeepEqual(result, expected) {
		t.Errorf("kidsWithCandies(%v, %d) = %v; expected %v", candies, extraCandies, result, expected)
	}
}

func TestKidsWithCandies3(t *testing.T) {
	candies := []int{12, 1, 12}
	extraCandies := 10
	expected := []bool{true, false, true}
	result := kidsWithCandies(candies, extraCandies)
	if !reflect.DeepEqual(result, expected) {
		t.Errorf("kidsWithCandies(%v, %d) = %v; expected %v", candies, extraCandies, result, expected)
	}
}