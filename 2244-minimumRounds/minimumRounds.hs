import Data.List (sort)

minimumRounds :: [Int] -> Int
minimumRounds = foldl1 sumIfPossible . map count . pack . sort

sumIfPossible :: Int -> Int -> Int
sumIfPossible (-1) _ = -1
sumIfPossible _ (-1) = -1
sumIfPossible a b = a + b

count :: [a] -> Int
count xs = if mida < 2 then (-1) else div (mida + 2) 3
  where
    mida = length xs

pack :: Eq a => [a] -> [[a]]
pack =
  (\(x : xs) -> tail x : xs)
    . ( foldl
          (\arr el -> if last (last arr) == el then init arr ++ [last arr ++ [el]] else arr ++ [[el]])
          =<< flip (:) [] . (flip (:) [] . head)
      )