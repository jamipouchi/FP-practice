package myPow

func myPow(x float64, n int) float64 {
	if n < 0 {
		return 1 / pow(x, -n)
	} else {
		return pow(x, n)
	}
}

func pow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	halfPow := myPow(x, n/2)
	twoHalfPow := halfPow * halfPow
	if n%2 == 0 {
		return twoHalfPow
	} else {
		return twoHalfPow * x
	}
}