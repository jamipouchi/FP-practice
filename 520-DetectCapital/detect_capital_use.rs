fn detect_capital_use(word: String) -> bool {
    /*
    word.chars().all(|c| c.is_lowercase())
        || word.chars().all(|c| c.is_uppercase())
        || (word.chars().next().unwrap().is_uppercase()
            && word.chars().skip(1).all(|c| c.is_lowercase()))
    */
    // we can actually do better, and unite 1st and third case by just checking all but first char!
    // This is true also for haskell and ts, but I've already written them and I am lazy :)
    word.chars().skip(1).all(|c| c.is_lowercase()) || word.chars().all(|c| c.is_uppercase())
}

#[cfg(test)]
mod tests {
    use crate::detect_capital_use;

    #[test]
    fn all_uppercase() {
        assert!(detect_capital_use("HOLA".to_string()))
    }
    #[test]
    fn all_lowercase() {
        assert!(detect_capital_use("hola".to_string()))
    }
    #[test]
    fn first_upper_rest_lower() {
        assert!(detect_capital_use("Hola".to_string()))
    }
    #[test]
    fn first_lower_rest_upper() {
        assert!(!detect_capital_use("hOLA".to_string()))
    }
}
