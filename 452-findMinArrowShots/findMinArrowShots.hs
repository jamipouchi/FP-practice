import Data.List (sort)

findMinArrowShots :: [[Int]] -> Int
findMinArrowShots = (countArrows . (last . head) =<< id) . sort
  where
    countArrows :: Int -> [[Int]] -> Int
    countArrows _ [] = 1
    countArrows lastPoint (x : xs) = if head x > lastPoint then 1 + countArrows (last x) xs else countArrows (min lastPoint (last x)) xs

main :: IO ()
main = do
  print $ findMinArrowShots [[10, 16], [2, 8], [1, 6], [7, 12]]
  print $ findMinArrowShots [[1, 2], [3, 4], [5, 6], [7, 8]]
  print $ findMinArrowShots [[1, 2], [2, 3], [3, 4], [4, 5]]
  print $ findMinArrowShots [[9, 12], [1, 10], [4, 11], [8, 12], [3, 9], [6, 9], [6, 7]]