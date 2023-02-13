fn count_odds(low: i32, high: i32) -> i32 {
    let parity = (low % 2) * (high % 2);
    (high - low + 1) / 2 + parity

    // (2..5) === (1..4)
    // (1..5) =/= (0..4)

    // odd * odd = odd (to check both are odd)
    // (low..high) ((high - low + 1)/ 2) + low % 2 == 0
}
