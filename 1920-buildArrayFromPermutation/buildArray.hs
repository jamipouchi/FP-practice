buildArray :: [Int] -> [Int]
buildArray nums = [nums !! x | x <- nums]

buildArrayDesugarized nums = do
  x <- nums
  return $ nums !! x

buildArrayFullyDesugarized :: [Int] -> [Int]
buildArrayFullyDesugarized nums = nums >>= \x -> return $ nums !! x
