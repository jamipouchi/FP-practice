package main

func lemonadeChange(bills []int) bool {
	fiveDollah := 0
	tenDollah := 0
	twentyDollah := 0
	for _, bill := range bills {
		toReturn := bill - 5
		for {
			if toReturn == 0 {
				break
			}
			if toReturn >= 20 && twentyDollah > 0 {
				toReturn -= 20
				twentyDollah--
				continue
			}
			if toReturn >= 10 && tenDollah > 0 {
				toReturn -= 10
				tenDollah--
				continue
			}
			if toReturn >= 5 && fiveDollah > 0 {
				toReturn -= 5
				fiveDollah--
				continue
			}
			return false
		}
		if bill == 5 {
			fiveDollah++
		} else if bill == 10 {
			tenDollah++
		} else if bill == 20 {
			twentyDollah++
		}
	}
	return true
}
