fn min_deletion_size(strs: Vec<String>) -> i32 {
    transpose(strs.into_iter().map(|str| str.chars().collect()).collect()) // this line is ugly af
        .into_iter()
        .filter(not!(sorted))
        .count() as i32
    // Okay. I love that there is a count.
}

fn transpose<T>(strs: Vec<Vec<T>>) -> Vec<Vec<T>>
where
    T: Clone,
{
    (0..strs[0].len())
        .map(|idx| strs.iter().map(|str| str[idx].clone()).collect())
        .collect()
}

fn sorted(char_word: &Vec<char>) -> bool {
    char_word
        .into_iter()
        .skip(1)
        .zip(char_word.into_iter())
        .all(|(a, b)| a >= b)
}

// Same as Ts, hate you need to write the not. I like having macros, don't like how fkn hard it was when trying to do it like in Ts
#[macro_export]
macro_rules! not {
    ($fun_name:ident) => {
        |arg| !$fun_name(arg)
    };
}

#[cfg(test)]
mod tests {
    use crate::min_deletion_size;
    macro_rules! vec_of_strings {
        ($($x:expr),*) => (vec![$($x.to_string()),*]);
    }

    #[test]
    fn ex1() {
        assert_eq!(min_deletion_size(vec_of_strings!["cba", "daf", "ghi"]), 1)
    }
    #[test]
    fn ex2() {
        assert_eq!(min_deletion_size(vec_of_strings!["a", "b"]), 0)
    }
    #[test]
    fn ex3() {
        assert_eq!(min_deletion_size(vec_of_strings!["zyx", "wvu", "tsr"]), 3)
    }
}
