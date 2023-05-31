package designparkingsystem

const (
	BIG    = 1
	MEDIUM = 2
	SMALL  = 3
)

type Capacity struct {
	filled int
	total  int
}
type ParkingSystem struct {
	big    Capacity
	medium Capacity
	small  Capacity
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{Capacity{0, big}, Capacity{0, medium}, Capacity{0, small}}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	switch carType {
	case BIG:
		if this.big.filled < this.big.total {
			this.big.filled++
			return true
		}
	case MEDIUM:
		if this.medium.filled < this.medium.total {
			this.medium.filled++
			return true
		}
	case SMALL:
		if this.small.filled < this.small.total {
			this.small.filled++
			return true
		}
	}
	return false
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */
