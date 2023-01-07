canCompleteCircuit :: [Int] -> [Int] -> Int
canCompleteCircuit gas cost = do
  let diff = zipWith (-) gas cost
  let n = length diff
  if any (>= 0) $ scanl1 (+) diff
    then do
      let twice = diff ++ diff
      head $ filter (\x -> isValidCircuit $ slice x (x + n) twice) [0 .. n -1]
    else (-1)

slice :: Int -> Int -> [a] -> [a]
slice from to = take (to - from + 1) . drop from

isValidCircuit :: [Int] -> Bool
isValidCircuit = all (>= 0) . scanl1 (+)

main = do
  print $ canCompleteCircuit [1, 2, 3, 4, 5] [3, 4, 5, 1, 2]
  print $ canCompleteCircuit [2, 3, 4] [3, 4, 3]
  print $ canCompleteCircuit [1, 6, 0, 4, 5] [3, 4, 5, 1, 2]