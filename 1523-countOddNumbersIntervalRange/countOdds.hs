countOdds :: Int -> Int -> Int
countOdds low high = div (high - low + 1) 2 + parity
  where
    parity = mod low 2 * mod high 2