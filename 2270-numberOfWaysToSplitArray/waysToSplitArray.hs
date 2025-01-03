waysToSplitArray :: [Int] -> Int
waysToSplitArray (x : xs) =
  fst $
    foldl
      ( \(count, cumSum) value ->
          if cumSum >= allSum - cumSum
            then (count + 1, cumSum + value)
            else (count, cumSum + value)
      )
      (0, x)
      xs
  where
    allSum = sum (x : xs)
