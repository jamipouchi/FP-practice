fn zero_filled_subarray(mut nums: Vec<i32>) -> i64 {
    nums.push(1);
    nums.into_iter().fold((0, 0), |(zeros, number_of_subarrays), num| {
        if num == 0 {
            (zeros + 1, number_of_subarrays)
        }
        else {
            (0, number_of_subarrays + zeros*(zeros+1) / 2)
        }
    }).1
}
