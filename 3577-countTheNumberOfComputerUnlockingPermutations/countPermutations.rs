struct Solution;

impl Solution {
    fn permutations(n: usize) -> i32 {
        let mut result: i64 = 1;
        for i in 1..=n {
            result = (result * i as i64) % 1000000007;
        }
        result as i32
    }
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let min = complexity[0];
        if complexity.iter().skip(1).any(|&x| x <= min) {
            return 0;
        }
        Self::permutations(complexity.len() - 1)
    }
}
