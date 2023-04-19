fn merge_alternately(word1: String, word2: String) -> String {
    word1
        .chars()
        .zip(word2.chars())
        .flat_map(|(c1, c2)| [c1, c2])
        .chain(word1.chars().skip(word2.len()))
        .chain(word2.chars().skip(word1.len()))
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_merge_alternately() {
        assert_eq!(
            merge_alternately("abc".to_string(), "pqr".to_string()),
            "apbqcr".to_string()
        );
        assert_eq!(
            merge_alternately("ab".to_string(), "pqrs".to_string()),
            "apbqrs".to_string()
        );
        assert_eq!(
            merge_alternately("abcd".to_string(), "pq".to_string()),
            "apbqcd".to_string()
        );
    }
}
