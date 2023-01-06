pub fn max_ice_cream(mut costs: Vec<i32>, coins: i32) -> i32 {
    costs.sort_by(|a, b| a.cmp(b));
    costs
        .into_iter()
        .scan(coins, |state, curr_cost| {
            *state = *state - curr_cost;
            if *state >= 0 {
                Some(*state)
            } else {
                None
            }
        })
        .count() as i32
}

// I like that you can finish early by returning None!
// (Thought it's a bit meh that I have to both explicit state and return, when most times they equal)

#[cfg(test)]
mod tests {
    use crate::max_ice_cream;

    #[test]
    fn ex1() {
        assert_eq!(max_ice_cream(vec![1, 3, 2, 4, 1], 7), 4)
    }
    #[test]
    fn ex2() {
        assert_eq!(max_ice_cream(vec![10, 6, 8, 7, 7, 8], 5), 0)
    }
    #[test]
    fn ex3() {
        assert_eq!(max_ice_cream(vec![1, 6, 3, 1, 2, 5], 20), 6)
    }
    #[test]
    fn ex4() {
        assert_eq!(
            max_ice_cream(vec![10, 2, 10, 10, 10, 10, 8, 2, 7, 8], 25),
            4
        )
    }
}
