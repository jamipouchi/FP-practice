modV = 10 ^ 9 + 7

countPermutations :: [Int] -> Int
countPermutations (min : xs) =
  if smallest min xs
    then permutations (length xs)
    else 0
  where
    smallest m = all (< m)

    permutations 0 = 1
    permutations n = n * permutations (n - 1) `mod` modV
