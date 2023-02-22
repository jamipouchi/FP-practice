shipWithinDays :: [Int] -> Int -> Int
shipWithinDays weights = binSearch weights (maximum weights) (sum weights)

binSearch :: [Int] -> Int -> Int -> Int -> Int
binSearch weights left right maxChunks
  | left >= right = left
  | otherwise = if checkPossible weights mid maxChunks then binSearch weights left mid maxChunks else binSearch weights (mid + 1) right maxChunks
  where
    mid = div (left + right) 2

checkPossible :: [Int] -> Int -> Int -> Bool
checkPossible weights limit maxChunks =
  fst
    ( foldl
        ( \(count, currSum) weight ->
            if currSum + weight > limit
              then (count + 1, weight)
              else (count, currSum + weight)
        )
        (0, 0)
        weights
    )
    < maxChunks