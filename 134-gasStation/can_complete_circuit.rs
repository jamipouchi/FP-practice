fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
    let (idx, _, total_sum) = gas.into_iter().zip(cost).enumerate().fold(
        (0, 0, 0),
        |(start_idx, sum_from_idx, total_sum), (curr_idx, (curr_gas, curr_cost))| {
            let curr_sum = sum_from_idx + curr_gas - curr_cost;
            if curr_sum < 0 {
                (curr_idx + 1, 0, total_sum + curr_gas - curr_cost)
            } else {
                (start_idx, curr_sum, total_sum + curr_gas - curr_cost)
            }
        },
    );
    if total_sum >= 0 {
        idx as i32
    } else {
        -1
    }
}

#[cfg(test)]
mod tests {
    use super::can_complete_circuit;

    #[test]
    fn ex1() {
        assert_eq!(
            can_complete_circuit(vec![1, 2, 3, 4, 5], vec![3, 4, 5, 1, 2]),
            3
        )
    }
    #[test]
    fn ex2() {
        assert_eq!(can_complete_circuit(vec![2, 3, 4], vec![3, 4, 3]), -1)
    }
    #[test]
    fn ex3() {
        assert_eq!(can_complete_circuit(vec![5, 1, 2, 3, 4], vec![4, 4, 1, 5, 1]), 4)
    }
}
