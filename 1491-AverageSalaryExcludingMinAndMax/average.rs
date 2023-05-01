// Functional approach
fn average(salary: Vec<i32>) -> f64 {
    salary
        .iter()
        .filter(|&s| s != salary.iter().max().unwrap() && s != salary.iter().min().unwrap())
        .sum::<i32>() as f64
        / (salary.len() - 2) as f64
}

// Imperative approach (Much more efficient)
fn average(salary: Vec<i32>) -> f64 {
    let mut min = salary[0];
    let mut max = salary[0];
    let mut sum = 0;
    let length = salary.len();
    for s in salary {
        if s < min {
            min = s;
        }
        if s > max {
            max = s;
        }
        sum += s;
    }
    (sum - min - max) as f64 / (length - 2) as f64
}

#[cfg(test)]
mod test{
    use super::*;
    #[test]
    fn test_average(){
        assert_eq!(average(vec![4000,3000,1000,2000]), 2500.00000);
        assert_eq!(average(vec![1000,2000,3000]), 2000.00000);
        assert_eq!(average(vec![6000,5000,4000,3000,2000,1000]), 3500.00000);
        assert_eq!(average(vec![8000,9000,2000,3000,6000,1000]), 4750.00000);
    }
}