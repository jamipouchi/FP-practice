shuffle :: [Int] -> Int -> [Int]
shuffle nums n = concat $ uncurry (zipWith (\x y -> [x, y])) (splitAt n nums)