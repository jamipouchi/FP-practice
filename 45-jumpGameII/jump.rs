fn jump(nums: Vec<i32>) -> i32 {
    if nums.len() == 1 {
        0
    } else {
        let mut memo: Vec<Result<Option<i32>, ()>> = vec![Ok(None); nums.len()];
        try_jumps(&nums, 0, &mut memo).unwrap()
    }
}

fn try_jumps(
    nums: &Vec<i32>,
    curr_pos: usize,
    memo: &mut Vec<Result<Option<i32>, ()>>,
) -> Option<i32> {
    let max_possible_jump = nums[curr_pos] as usize;
    let mut min_number_jumps: Option<i32> = None;
    if max_possible_jump == 0 {
        memo[curr_pos] = Err(());
        None
    } else if curr_pos + max_possible_jump >= nums.len() - 1 {
        // No need to memoize the end
        Some(1)
    } else {
        for jump in 1..=max_possible_jump {
            match memo[curr_pos + jump] {
                Ok(Some(calculated_jumps)) => {
                    min_number_jumps = match min_number_jumps {
                        None => Some(calculated_jumps),
                        Some(previous_jumps) => Some(previous_jumps.min(calculated_jumps)),
                    }
                }
                Ok(None) => {
                    if let Some(calculated_jumps) = try_jumps(nums, curr_pos + jump, memo) {
                        min_number_jumps = match min_number_jumps {
                            None => Some(calculated_jumps),
                            Some(previous_jumps) => Some(previous_jumps.min(calculated_jumps)),
                        }
                    }
                }
                Err(()) => {}
            }
        }
        if let Some(min_calculated_jumps) = min_number_jumps {
            memo[curr_pos] = Ok(Some(1 + min_calculated_jumps));
            Some(1 + min_calculated_jumps)
        } else {
            memo[curr_pos] = Err(());
            None
        }
    }
}

// This is some good code :)

#[cfg(test)]
mod tests {
    use super::jump;
    #[test]
    fn test1() {
        assert_eq!(jump(vec![2, 3, 1, 1, 4]), 2)
    }
    #[test]
    fn test2() {
        assert_eq!(jump(vec![2, 3, 0, 1, 4]), 2)
    }

    #[test]
    fn test3() {
        assert_eq!(jump(vec![2, 1, 1, 1, 1]), 3)
    }
    #[test]
    fn test4() {
        assert_eq!(jump(vec![5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0]), 3)
    }
}
