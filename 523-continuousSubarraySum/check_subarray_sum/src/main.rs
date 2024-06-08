struct Solution;

// This gives Time Limit Exceeded.
// Looking at the solutions, you had to prefix_sum with a hashet, and do it in one go O(N), not O(N^2).
impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        let mut memo = Vec::<i32>::with_capacity(nums.len() + 1);
        memo.push(0);
        for (idx, num) in nums.iter().enumerate().skip(1) {
            memo.push(memo[idx - 1] + num);
        }
        for left in 0..nums.len() - 1 {
            for right in (left + 2)..nums.len() {
                //sum = nums.iter().take(right + 1).skip(left).sum();
                // This needs to be more efficient...
                // We could do this by holding a memo on the prefix sum, and then simply:
                // sum[left,right] = memo[right] - memo[left]
                let sum = memo[right] - memo[left];
                if sum % k == 0 {
                    return true;
                }
            }
        }
        return false;
    }
}
