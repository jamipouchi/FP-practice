package main

import "strconv"

func countSeniors(details []string) int {
	seniors := 0
	for _, detail := range details {
		age, _ := strconv.Atoi(detail[11:13])
		if age > 60 {
			seniors++
		}
	}
	return seniors
}
