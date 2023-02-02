use std::collections::HashMap;

fn min_time(n: i32, edges: Vec<Vec<i32>>, has_apple: Vec<bool>) -> i32 {
    let mut adjacency_list = HashMap::new();
    for edge in edges {
        adjacency_list
            .entry(edge[0])
            .and_modify(|edges: &mut Vec<i32>| edges.push(edge[1]))
            .or_insert(vec![edge[1]]);
    }
    helper(&0, &adjacency_list, &has_apple, 0).1
}

fn helper(
    curr_node: &i32,
    adjacency_list: &HashMap<i32, Vec<i32>>,
    has_apple: &Vec<bool>,
    dist: i32,
) -> (i32, i32) {
    let mut min_dist = 0;
    if has_apple[*curr_node as usize] {
        min_dist = dist;
    }

    if adjacency_list.contains_key(curr_node) {
        for reachable_node in adjacency_list.get(curr_node).unwrap() {
            min_dist += helper(reachable_node, adjacency_list, has_apple, dist + 1).1;
        }
    }
    (0, min_dist)
}

#[cfg(test)]
mod tests {
    use super::min_time;
    macro_rules! vec_of_vectors {
        ($($x:expr),*) => (vec![$($x.to_vec()), *]);
    }
    #[test]
    fn ex1() {
        assert_eq!(
            min_time(
                7,
                vec_of_vectors![[0, 1], [0, 2], [1, 4], [1, 5], [2, 3], [2, 6]],
                vec![false, false, true, false, true, true, false]
            ),
            8
        )
    }
    #[test]
    fn ex2() {
        assert_eq!(
            min_time(
                7,
                vec_of_vectors![[0, 1], [0, 2], [1, 4], [1, 5], [2, 3], [2, 6]],
                vec![false, false, true, false, false, true, false]
            ),
            6
        )
    }
    #[test]
    fn ex3() {
        assert_eq!(
            min_time(
                7,
                vec_of_vectors![[0, 1], [0, 2], [1, 4], [1, 5], [2, 3], [2, 6]],
                vec![true, false, false, false, false, false, false]
            ),
            0
        )
    }
}
