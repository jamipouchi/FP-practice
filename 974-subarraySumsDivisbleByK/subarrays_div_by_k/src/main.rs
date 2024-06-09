use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
        let cumSum = nums.iter().fold(vec![0], |mut acc, num| {
            acc.push(((acc.last().unwrap() + num) % k + k) % k);
            return acc;
        });
        // We want to find all pairs (i,j) such that:
        // (cumSum[j] - cumSum[i]) % k == 0 =>
        // (cumSum[j] % k - cumSum[i] % k) % k == 0 =>
        // Note we directly store each value % k in cumSum.
        // pairs += values[cumSum[i]]
        let mut times_seen = HashMap::<i32, u32>::from([(0, 1)]);
        let mut count = 0;
        for i in 1..cumSum.len() {
            count += times_seen.get(&cumSum[i]).unwrap_or(&0);
            *times_seen.entry(cumSum[i]).or_insert(0) += 1
        }
        count as i32
    }
}
