countCollisions :: String -> Int
countCollisions [] = 0
countCollisions ('L' : xs) = countCollisions xs
countCollisions xs = countCollisionsR (reverse xs)
  where
    countCollisionsR [] = 0
    countCollisionsR ('R' : ys) = countCollisionsR ys
    countCollisionsR ys = sum [1 | c <- ys, c /= 'S']
