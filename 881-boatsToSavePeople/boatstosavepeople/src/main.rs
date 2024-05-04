struct Solution;

impl Solution {
    pub fn num_rescue_boats(people: Vec<i32>, limit: i32) -> i32 {
        let mut people = people;
        people.sort();
        let mut small_idx = 0;
        let mut big_idx = people.len() - 1;
        let mut total_boats = 0;
        while small_idx <= big_idx {
            if people[small_idx] + people[big_idx] <= limit {
                small_idx += 1;
            }
            big_idx = if big_idx == 0 {
                total_boats += 1;
                break;
            } else {
                big_idx - 1
            };
            total_boats += 1;
        }
        total_boats
    }
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_num_rescue_boats() {
        assert_eq!(Solution::num_rescue_boats(vec![1, 2], 3), 1);
        assert_eq!(Solution::num_rescue_boats(vec![3, 2, 2, 1], 3), 3);
        assert_eq!(Solution::num_rescue_boats(vec![3, 5, 3, 4], 5), 4);
    }
}
