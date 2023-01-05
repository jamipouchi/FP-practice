fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
    points.sort();
    count_arrows(points[0][1], points.clone())
}

fn count_arrows(last_point: i32, mut points: Vec<Vec<i32>>) -> i32 {
    println!("{}", last_point);
    match &mut points[..] {
        [] => 1,
        [x, xs @ ..] => {
            println!("{:?} {:?}", x, xs);
            if x[0] > last_point {
                1 + count_arrows(x[1], xs.to_vec())
            } else {
                count_arrows(std::cmp::min(x[1], last_point), xs.to_vec())
            }
        }
    }
}

// It gives tl. It doesn't pass my tests. I don't know why xddddd wtf i hate rust xd

/* I saw this solution, which is beautiful!
pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
    points.sort_unstable_by_key(|b| b[1]);
    points.iter().skip(1).fold((1, points[0][1]), |(rez, right), b|
        if right < b[0] {
            (rez + 1, b[1])
        } else {
            (rez, right)
        }
    ).0
}
*/

#[cfg(test)]
mod tests {
    use crate::find_min_arrow_shots;
    macro_rules! vec_of_vectors {
        ($($x:expr),*) => (vec![$($x.to_vec()), *]);
    }
    #[test]
    fn ex1() {
        assert_eq!(
            find_min_arrow_shots(vec_of_vectors![[10, 16], [2, 8], [1, 6], [7, 12]]),
            2
        )
    }
    #[test]
    fn ex2() {
        assert_eq!(
            !find_min_arrow_shots(vec_of_vectors![[1, 2], [3, 4], [5, 6], [7, 8]]),
            4
        )
    }
    #[test]
    fn ex3() {
        assert_eq!(
            !find_min_arrow_shots(vec_of_vectors![[1, 2], [2, 3], [3, 4], [4, 5]]),
            2
        )
    }
    #[test]
    fn ex4() {
        assert_eq!(
            !find_min_arrow_shots(vec_of_vectors![
                [9, 12],
                [1, 10],
                [4, 11],
                [8, 12],
                [3, 9],
                [6, 9],
                [6, 7]
            ]),
            2
        )
    }
}
