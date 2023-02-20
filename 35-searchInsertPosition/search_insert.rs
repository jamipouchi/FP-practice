use std::cmp::Ordering::{Equal, Greater, Less};

pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
    fn search_recurse(nums: Vec<i32>, target: i32, left: i32, right: i32) -> i32 {
        if left > right {
            return left;
        }
        let mid = left + (right - left) / 2;
        match nums[mid as usize].cmp(&target) {
            Equal => mid,
            Greater => search_recurse(nums, target, left, mid - 1),
            Less => search_recurse(nums, target, mid + 1, right),
        }
    }

    let last_index = nums.len() as i32 - 1;
    search_recurse(nums, target, 0, last_index)
}
