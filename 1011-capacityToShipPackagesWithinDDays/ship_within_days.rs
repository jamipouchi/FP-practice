fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
    let max_weight = weights.clone().into_iter().max().unwrap();
    let sum_weights = weights.clone().into_iter().sum();
    bin_search(&weights, max_weight, sum_weights, days)
}

fn bin_search(weights: &Vec<i32>, left: i32, right: i32, max_chunks: i32) -> i32 {
    println!("left: {}, right: {}", left, right);
    if left >= right {
        left
    } else {
        let mid = (left + right) / 2;
        if check_possible(weights, mid, max_chunks) {
            bin_search(weights, left, mid, max_chunks)
        } else {
            bin_search(weights, mid + 1, right, max_chunks)
        }
    }
}

fn check_possible(weights: &Vec<i32>, limit: i32, max_chunks: i32) -> bool {
    println!("limit: {}", limit);
    weights
        .into_iter()
        .fold((0, 0), |(count, curr_sum), weight| {
            if curr_sum + *weight > limit {
                (count + 1, *weight)
            } else {
                (count, curr_sum + *weight)
            }
        })
        .0
        < max_chunks
}

#[cfg(test)]
mod tests {
    use super::ship_within_days;

    #[test]
    fn test1() {
        assert_eq!(ship_within_days(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5), 15)
    }
}
