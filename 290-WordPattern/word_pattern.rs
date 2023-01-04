fn word_pattern(pt: String, s: String) -> bool {
    if pt.is_empty() && s.is_empty() {
        true
    } else if pt == "" || s == "" {
        false
    } else {
        let p = pt.chars().next().unwrap();
        let s_words: &Vec<&str> = &s.split_ascii_whitespace().collect();
        let s_first = s_words[0];
        pt.chars()
            .map(|c| c == p)
            .eq(s_words.into_iter().map(|word| word == &s_first))
            && word_pattern(
                pt.chars().filter(|c| c != &p).collect(),
                s_words // This is a mess.
                    .to_owned()
                    .into_iter()
                    .filter(|w| w != &s_first)
                    .collect::<Vec<&str>>()
                    .join(" "),
            )
    }
}

#[cfg(test)]
mod tests {
    use crate::word_pattern;
    #[test]
    fn ex1() {
        assert!(word_pattern("abba".to_string(), "dog cat cat dog".to_string()))
    }
    #[test]
    fn ex2() {
        assert!(!word_pattern("abba".to_string(), "dog cat cat fish".to_string()))
    }
    #[test]
    fn ex3() {
        assert!(!word_pattern("aaaa".to_string(), "dog cat cat dog".to_string()))
    }
}
