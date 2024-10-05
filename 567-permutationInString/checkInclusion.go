package main

func checkInclusion(s1, s2 string) bool {
	toFind := make(map[byte]int)
	ls1 := len(s1)
	ls2 := len(s2)
	matches := 0
	if ls2 < ls1 {
		return false
	}
	for i := 0; i < ls1; i++ {
		toFind[s1[i]] += 1
	}
	toMatch := len(toFind)
	for i := 0; i < ls1; i++ {
		c := s2[i]
		if count, has := toFind[c]; has {
			if count == 1 {
				matches++
			} else if count == 0 {
				matches--
			}
			toFind[c] -= 1
		}
	}
	// if Every(toFind, func(key byte, val int) bool { return val == 0 }) {
	// 	return true
	// }
	if matches == toMatch {
		return true
	}
	for i := 0; i+ls1 < ls2; i++ {
		forgetting := s2[i]
		if count, has := toFind[forgetting]; has {
			if count == -1 {
				matches++
			} else if count == 0 {
				matches--
			}
			toFind[forgetting] += 1
		}
		adding := s2[i+ls1]
		if count, has := toFind[adding]; has {
			if count == 1 {
				matches++
			} else if count == 0 {
				matches--
			}
			toFind[adding] -= 1
		}
		if matches == toMatch {
			return true
		}
		// if Every(toFind, func(key byte, val int) bool { return val == 0 }) {
		// 	return true
		// }
	}
	return false
}

// func Every[K comparable, V any](m map[K]V, predicate func(K, V) bool) bool {
// 	for key, value := range m {
// 		if !predicate(key, value) {
// 			return false
// 		}
// 	}
// 	return true
// }
