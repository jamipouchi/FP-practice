import Data.List (sort)

maxIceCream :: [Int] -> Int -> Int
maxIceCream costs coins = length (takeWhile (>= 0) (scanl (-) coins $ sort costs)) - 1

main = do
  print $ maxIceCream [1, 3, 2, 4, 1] 7
  print $ maxIceCream [10, 6, 8, 7, 7, 8] 5
  print $ maxIceCream [1, 6, 3, 1, 2, 5] 20
