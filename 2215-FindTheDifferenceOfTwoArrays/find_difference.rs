use std::collections::HashSet;

fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
    let set1 = HashSet::<i32>::from_iter(nums1);
    let mut set2 = HashSet::<i32>::from_iter(nums2);

    let mut ans = vec![vec![], vec![]];

    for num in set1 {
        if set2.contains(&num) {
            set2.remove(&num);
        }
        else {
            ans[0].push(num);
        }
    }

    for num in set2 {
        ans[1].push(num);
    }

    ans
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test1() {
        let nums1 = vec![1, 2, 3];
        let nums2 = vec![2, 4, 6];
        let ans = vec![vec![1,3], vec![4,6]];
        assert_eq!(find_difference(nums1, nums2), ans);
    }
    #[test]
    fn test2() {
        let nums1 = vec![1, 2, 3, 3];
        let nums2 = vec![1, 1, 2, 2];
        let ans = vec![vec![3], vec![]];
        assert_eq!(find_difference(nums1, nums2), ans);
    }
}
