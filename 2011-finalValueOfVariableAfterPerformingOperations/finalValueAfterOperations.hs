finalValueAfterOperations :: [[Char]] -> Int
finalValueAfterOperations = foldl fn 0
  where
    fn cum (_ : x : _)
      | x == '+' = cum + 1
      | x == '-' = cum - 1

test = do
  let test1 = ["--X", "X++", "X++"]
  let res1 = finalValueAfterOperations test1
  print res1

  let test2 = ["++X", "++X", "X++"]
  let res2 = finalValueAfterOperations test2
  print res2

  let test3 = ["X++", "++X", "--X", "X--"]
  let res3 = finalValueAfterOperations test3
  print res3
