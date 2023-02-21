fn single_non_duplicate(nums: Vec<i32>) -> i32 {
    find_rec(&nums, 0, nums.len() - 1)
}

fn find_rec(nums: &Vec<i32>, left: usize, right: usize) -> i32 {
    if left >= right {
        nums[left]
    } else {
        let mut mid = (left + right) / 2;
        if mid % 2 == 1 {
            mid -= 1;
        }
        if nums[mid] != nums[mid + 1] {
            find_rec(nums, left, mid.saturating_sub(1))
        } else {
            find_rec(nums, mid + 2, right)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::single_non_duplicate;
    #[test]
    fn test_1() {
        assert_eq!(single_non_duplicate(vec![1,2,2,3,3]), 1)
    }
}