fn total_fruit(fruits: Vec<i32>) -> i32 {
    let start = fruits[0];
    let (_, _, (total_max, curr_max)) = fruits.into_iter().enumerate().fold(
        (0, (start, None), (0, 0)),
        |(left, (curr, prev), (total_max, curr_max)), (right, fruit)| {
            if curr != fruit {
                if prev.map_or(false, |prev| prev != fruit) {
                    (
                        right,
                        (fruit, Some(curr)),
                        (total_max.max(curr_max), (right - left) as i32 + 1),
                    )
                } else {
                    (right, (fruit, Some(curr)), (total_max, curr_max + 1))
                }
            } else {
                (left, (curr, prev), (total_max, curr_max + 1))
            }
        },
    );
    total_max.max(curr_max)
}

// This is inspired, cuz I suck! (I didn't think about handling last fruit with Option)

#[cfg(test)]
mod tests {
    use super::total_fruit;
    #[test]
    fn test0() {
        assert_eq!(total_fruit(vec![1, 2, 1]), 3)
    }
    #[test]
    fn test1() {
        assert_eq!(total_fruit(vec![0, 0, 1, 1]), 4)
    }
    #[test]
    fn test2() {
        assert_eq!(total_fruit(vec![0, 1, 2, 2]), 3)
    }
    #[test]
    fn test3() {
        assert_eq!(total_fruit(vec![1, 2, 3, 2, 2]), 4)
    }
    #[test]
    fn test4() {
        assert_eq!(total_fruit(vec![3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]), 5)
    }
    #[test]
    fn test5() {
        assert_eq!(total_fruit(vec![0, 1, 6, 6, 4, 4, 6]), 5)
    }
}
