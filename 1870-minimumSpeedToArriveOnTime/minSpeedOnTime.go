package minimumspeedtoarriveontime

import (
	"math"
)

func minSpeedOnTime(dist []int, hour float64) int {
	if hour <= float64(len(dist)-1) {
		return -1
	}
	// This could be better bounded
	maxSpeed := int(1e7)
	minSpeed := 1
	for minSpeed < maxSpeed {
		nextSpeed := (maxSpeed + minSpeed) / 2
		if check(dist, hour, nextSpeed) {
			maxSpeed = nextSpeed
		} else {
			minSpeed = nextSpeed + 1
		}
	}
	return minSpeed
}

func check(dist []int, hour float64, speed int) bool {
	speedF := float64(speed)
	time := 0.
	for _, dist := range dist[:len(dist)-1] {
		time += math.Ceil(float64(dist) / speedF)
	}
	time += float64(dist[len(dist)-1]) / speedF
	return time <= hour
}
