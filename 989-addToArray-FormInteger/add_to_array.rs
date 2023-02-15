fn add_to_array_form(num: Vec<i32>, mut k: i32) -> Vec<i32> {
    if k == 0 {
        num
    } else {
        let mut a_iter = num.into_iter().rev();
        let mut b_iter = std::iter::from_fn(move || {
            if k == 0 {
                None
            } else {
                let b = k % 10;
                k /= 10;
                Some(b)
            }
        });
        let mut carry = false;
        let mut reversed_number: Vec<i32> =
            std::iter::from_fn(move || match (a_iter.next(), b_iter.next()) {
                (None, None) => {
                    if carry {
                        carry = false;
                        Some(1)
                    } else {
                        None
                    }
                }
                (a, b) => {
                    let a = a.unwrap_or(0);
                    let b = b.unwrap_or(0);
                    let a_plus_b = a + b + if carry { 1 } else { 0 };
                    if a_plus_b >= 10 {
                        carry = true;
                        Some(a_plus_b - 10)
                    } else {
                        carry = false;
                        Some(a_plus_b)
                    }
                }
            })
            .collect();
        reversed_number.reverse();
        reversed_number
    }
}

#[cfg(test)]
mod tests {
    use super::add_to_array_form;
    #[test]
    fn test0() {
        assert_eq!(
            add_to_array_form(vec![9, 9, 9, 9, 9, 9, 9, 9, 9, 9], 1),
            vec![1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        )
    }
}
