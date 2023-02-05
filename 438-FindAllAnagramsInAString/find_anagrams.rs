use std::collections::HashMap;

fn find_anagrams(s: String, p: String) -> Vec<i32> {
    let size = p.len();
    let mut letters = HashMap::new();
    p.chars().for_each(|c| {
        letters
            .entry(c)
            .and_modify(|count| *count += 1)
            .or_insert(1);
    });
    let mut correct_idx = vec![];
    s.chars()
        .collect::<Vec<char>>()
        .windows(size)
        .enumerate()
        .for_each(|(idx, window)| {
            if check_window_and_update_idx(window, letters.clone()) {
                correct_idx.push(idx as i32)
            }
        });
    correct_idx
}

fn check_window_and_update_idx(window: &[char], mut letters: HashMap<char, i32>) -> bool {
    for c in window.into_iter() {
        match letters.get(c) {
            None => return false,
            Some(0) => return false,
            Some(x) => letters.insert(*c, x - 1),
        };
    }
    true
}

// This solution actually TL's!!!
// I believe .windows() is a stupid idea. it's better just keeping track of changing chars :)

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test1() {
        assert_eq!(
            find_anagrams("abab".to_string(), "ab".to_string()),
            vec![0, 1, 2]
        )
    }
}
