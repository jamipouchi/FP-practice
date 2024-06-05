fn main() {
    println!("Hello, world!");
}

struct Solution {}

impl Solution {
    pub fn common_chars(words: Vec<String>) -> Vec<String> {
        let mut matching_chars = vec![usize::MAX; 26];
        words.iter().for_each(|word| {
            let mut word_char_count = vec![0; 26];
            word.chars().for_each(|c| {
                word_char_count[(c as u8 - 'a' as u8) as usize] += 1;
            });
            for i in 0..26 {
                matching_chars[i] = std::cmp::min(matching_chars[i], word_char_count[i]);
            }
        });
        matching_chars
            .iter()
            .enumerate()
            .fold(Vec::new(), |mut acc, (i, &count)| {
                for _ in 0..count {
                    acc.push(((i as u8 + 'a' as u8) as char).to_string());
                }
                acc
            })
    }
}
