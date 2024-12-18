import Data.List (sortBy)

minimumDifference :: [Int] -> Int -> Int
minimumDifference nums k = minKdiff $ sortBy (\a b -> compare (-a) (-b)) nums
  where
    minKdiff sortedList =
      let (a : rest) = sortedList
       in if length sortedList >= k
            then min (a - sortedList !! (k - 1)) (minKdiff rest)
            else maxBound
