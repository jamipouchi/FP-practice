countAndSay :: Int -> String
countAndSay 1 = "1"
countAndSay n = encode $ countAndSay (n - 1)

countAndSay' :: Int -> String
countAndSay' n = iterate encode "1" !! (n - 1)

encode :: String -> String
encode [] = []
encode (c : cs) = show (count + 1) ++ [c] ++ encode rest
  where
    (count, rest) = dropAndCount c cs

dropAndCount :: (Eq a) => a -> [a] -> (Int, [a])
dropAndCount = dropAndCount' 0
  where
    dropAndCount' :: (Eq a) => Int -> a -> [a] -> (Int, [a])
    dropAndCount' count c [] = (count, [])
    dropAndCount' count c (x : xs)
      | c == x =
          let (nextCount, rest) = dropAndCount c xs
           in (nextCount + 1, rest)
      | otherwise = (count, x : xs)

main = do
  print $ countAndSay 4
  print $ countAndSay 1
