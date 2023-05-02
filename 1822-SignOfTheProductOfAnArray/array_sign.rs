fn array_sign(nums: Vec<i32>) -> i32 {
    nums.iter()
        .scan(1, |sign, num| {
            if *sign == 0 {
                None
            } else {
                *sign *= num.signum();
                Some(*sign)
            }
        })
        .last()
        .unwrap_or(0)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let nums = vec![-1, -2, -3, -4, 3, 2, 1];
        assert_eq!(array_sign(nums), 1);
    }

    #[test]
    fn test_2() {
        let nums = vec![1, 5, 0, 2, -3];
        assert_eq!(array_sign(nums), 0);
    }

    #[test]
    fn test_3() {
        let nums = vec![-1, 1, -1, 1, -1];
        assert_eq!(array_sign(nums), -1);
    }
}