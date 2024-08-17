maxPoints :: [[Int]] -> Int
maxPoints = maximum . foldl1 addRows
  where
    addRows :: [Int] -> [Int] -> [Int]
    addRows = zipWith (+) . findMaxAtEveryPosition
    findMaxAtEveryPosition :: [Int] -> [Int]
    findMaxAtEveryPosition list = map (getMaxAtPos list) [0 .. l]
      where
        l = length list

getMaxAtPos :: [Int] -> Int -> Int
getMaxAtPos list index = maximum $ mapMax 0 list index
  where
    mapMax :: Int -> [Int] -> Int -> [Int]
    mapMax _ [] _ = []
    mapMax curr (x : rest) index = x - abs (curr - index) : mapMax (curr + 1) rest index

-- How dafuq do I write this. Some Kind of fold

{-
                        g
    3 1 1 1 => 3 1 1 1 => (3 0 -1 -1 => 3) | (2 1 0 -1 => 2) | (1 0 1 0 => 1) | (0 -1 0 1 => 1)
    1 1 1 3 => 4 3 2 4 => 4                  3                 2                4
    1 1 1 3 => 5 4 4 7 => 7

    1 2 3 => 1 2 3
    1 5 1 => 1 7 4
    3 1 1 => 9 8 5 => 9
-}
