fn can_place_flowers(mut flowerbed: Vec<i32>, n: i32) -> bool {
    flowerbed.splice(0..0, [0]);
    flowerbed.push(0);
    let placable_flowers: usize = flowerbed
        .split(|plot| *plot == 1)
        .filter_map(|plot_space| {
            if plot_space.is_empty() {
                None
            }
            else {
                Some((plot_space.len() - 1) / 2)
            }
        }).sum();
    placable_flowers as i32 >= n
}

#[cfg(test)]
mod tests {
    use super::can_place_flowers;
    #[test]
    fn test1() {
        assert!(can_place_flowers(vec![1, 0, 0, 0, 1], 1));
    }
    #[test]
    fn test2() {
        assert!(!can_place_flowers(vec![1,0,1,0,0,1,0,0,0,1], 2))
    }
    #[test]
    fn test3() {
        assert!(can_place_flowers(vec![0,0,1,0,1], 1))
    }
}
