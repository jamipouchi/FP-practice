fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
    let (left, right) = nums.split_at(n as usize);
    left.into_iter()
        .zip(right.into_iter())
        .flat_map(|(&l, &r)| [l, r])
        .collect()
}

#[cfg(test)]
mod tests {
    use super::shuffle;
    #[test]
    fn test1() {
        assert_eq!(shuffle(vec![2,5,1,3,4,7], 3), vec![2,3,5,4,1,7])
    }
}