/*
    THIS IS NOT CORRECT. IT DOES NOT CONSIDER NON INTEGER SLOPES, OR NON INTEGER ORIGIN CROSSES
*/

fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {
    let (x0, y0) = (coordinates[0][0], coordinates[0][1]);
    let (x1, y1) = (coordinates[1][0], coordinates[1][1]);
    if (x1 - x0) == 0 {
        return coordinates.into_iter().skip(2).all(|c| c[0] == x0);
    }
    let m = (y1 - y0) / (x1 - x0);
    let n = y0 - m * x0;
    coordinates.into_iter().skip(2).all(|c| {
        let (x, y) = (c[0], c[1]);
        y == m*x + n
    })
}


#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test1() {
        let coordinates = vec![vec![1,2],vec![2,3],vec![3,4],vec![4,5],vec![5,6],vec![6,7]];
        assert_eq!(check_straight_line(coordinates), true);
    }
    #[test]
    fn test2() {
        let coordinates = vec![vec![1,1],vec![2,2],vec![3,4],vec![4,5],vec![5,6],vec![7,7]];
        assert_eq!(check_straight_line(coordinates), false);
    }
}