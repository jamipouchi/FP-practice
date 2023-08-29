package bestclosingtime

var cost []int
var minIdx int

func bestClosingTime(customers string) int {
	cost = make([]int, len(customers)+1)
	cost[len(customers)] = 0
	for i := len(customers) - 1; i >= 0; i-- {
		cost[i] = cost[i+1]
		if customers[i] == 'Y' {
			cost[i]++
		}
	}
	bestClosingTimeFrom(0, customers)
	return minIdx
}

func bestClosingTimeFrom(idx int, customers string) int {
	nextIdx := 0
	for nextIdx < len(customers) && customers[nextIdx] == 'Y' {
		nextIdx++
	}
	if nextIdx == len(customers) {
		minIdx = idx + nextIdx
		return 0
	}
	currCost := cost[idx+nextIdx]
	bestNextCost := 1 + bestClosingTimeFrom(idx+nextIdx+1, customers[nextIdx+1:])
	if bestNextCost < currCost {
		return bestNextCost
	} else {
		minIdx = idx + nextIdx
		return currCost
	}
}

// THIS CAN BE DONE MUCH BETTER! (HASKELL HAS HURT ME!)
func bestClosingTime2(customers string) int {
	// This won't work in new golang version as min is now a keyword!
	curr, min := 0, 0
	earliest := 0
	for i, c := range customers {
		switch c {
		case 'Y':
			curr -= 1
			if curr < min {
				min = curr
				earliest = i + 1
			}
		case 'N':
			curr += 1
		}
	}
	return earliest
}
