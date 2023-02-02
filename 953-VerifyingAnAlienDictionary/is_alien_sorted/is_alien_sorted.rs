fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
    words
        .windows(2)
        .all(|window| greater(&window[0], &window[1], &order))
}

fn greater(left: &String, right: &String, order: &String) -> bool {
    if let Some((a, b)) = left
        .chars()
        .zip(right.chars())
        .skip_while(|(charL, charR)| charL == charR)
        .next()
    {
        order.find(a) < order.find(b)
    } else {
        left.len() < right.len()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test1() {
        assert!(is_alien_sorted(
            vec!["hello".to_string(), "leetcode".to_string()],
            "hlabcdefgijkmnopqrstuvwxyz".to_string()
        ))
    }
}
