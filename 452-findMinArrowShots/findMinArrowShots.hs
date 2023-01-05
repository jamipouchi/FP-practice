import Data.List (sort)

findMinArrowShots :: [[Int]] -> Int
findMinArrowShots = helper . (pure . last . head) =<< sort
  where
    helper :: Maybe Int -> [[Int]] -> Int
    helper Nothing = const 0
    helper (Just lastPoint) = (+ 1) . (helper . maybeGetLast =<< dropWhile ((>=) lastPoint . head))
    maybeGetLast :: [[Int]] -> Maybe Int
    maybeGetLast [] = Nothing
    maybeGetLast (fst : rest) = pure $ last fst

main :: IO ()
main = do
  print $ findMinArrowShots [[10, 16], [2, 8], [1, 6], [7, 12]]
  print $ findMinArrowShots [[1, 2], [3, 4], [5, 6], [7, 8]]
  print $ findMinArrowShots [[1, 2], [2, 3], [3, 4], [4, 5]]