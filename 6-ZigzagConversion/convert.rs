fn convert(s: String, num_rows: i32) -> String {
    let mut zigzags: Vec<_> = (0..num_rows)
        .chain((1..num_rows - 1).rev())
        .cycle()
        .zip(s.chars())
        .collect();
    zigzags.sort_by_key(|&(row, _)| row);
    zigzags.into_iter().map(|(_, c)| c).collect()
}

// That's genius! Don't think it's the most efficient as it is O(n*log(n)), but it's sooo cool
// It is copied btw