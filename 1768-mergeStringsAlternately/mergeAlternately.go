package mergeAlternately

func mergeAlternately(word1, word2 string) string {
	res := make([]byte, 0, len(word1)+len(word2))
	i, j := 0, 0
	for i < len(word1) && j < len(word2) {
		res = append(res, word1[i], word2[j])
		i++
		j++
	}

	for i < len(word1) {
		res = append(res, word1[i])
		i++
	}

	for j < len(word2) {
		res = append(res, word2[j])
		j++
	}

	return string(res)
}

func TestMergeAlternately(t *testing.T) {
	word1 := "abc"
	word2 := "pqr"
	want := "apbqcr"
	got := mergeAlternately(word1, word2)
	if got != want {
		t.Errorf("mergeAlternately(%q, %q) = %q; want %q", word1, word2, got, want)
	}
}

func TestMergeAlternately2(t *testing.T) {
	word1 := "ab"
	word2 := "pqrs"
	want := "apbqrs"
	got := mergeAlternately(word1, word2)
	if got != want {
		t.Errorf("mergeAlternately(%q, %q) = %q; want %q", word1, word2, got, want)
	}
}

func TestMergeAlternately3(t *testing.T) {
	word1 := "abcd"
	word2 := "pq"
	want := "apbqcd"
	got := mergeAlternately(word1, word2)
	if got != want {
		t.Errorf("mergeAlternately(%q, %q) = %q; want %q", word1, word2, got, want)
	}
}
