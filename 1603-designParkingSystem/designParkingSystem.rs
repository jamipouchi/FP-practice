struct ParkingSystem {
    big : (i32,i32),
    medium : (i32,i32),
    small : (i32,i32),
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ParkingSystem {

    // I couldn't make work defining BIG MEDIUM AND SMALL as constants

    fn new(big: i32, medium: i32, small: i32) -> Self {
        ParkingSystem {
            big: (0,big),
            medium: (0,medium),
            small: (0,small),
        }
    }
    
    fn add_car(&mut self, car_type: i32) -> bool {
        println!("{} {} {}", self.big.0, self.medium.0, self.small.0);
        match car_type {
            1 => {
                if self.big.0 < self.big.1 {
                    self.big.0 += 1;
                    true
                } else {
                    false
                }
            },
            2 => {
                if self.medium.0 < self.medium.1 {
                    self.medium.0 += 1;
                    true
                } else {
                    false
                }
            },
            3 => {
                if self.small.0 < self.small.1 {
                    self.small.0 += 1;
                    true
                } else {
                    false
                }
            },
            _ => false,
        }
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * let obj = ParkingSystem::new(big, medium, small);
 * let ret_1: bool = obj.add_car(carType);
 */