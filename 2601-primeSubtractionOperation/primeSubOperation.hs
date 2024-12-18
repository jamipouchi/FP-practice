primeSubOperation :: [Int] -> Bool
primeSubOperation nums = (> 0) $ foldl (\minPoss nextVal -> if minPoss < 0 then minPoss else nextVal - getNextMin (nextVal - minPoss)) 0 nums
  where
    primes = sieve [2 .. (maximum nums)]
    getNextMin :: Int -> Int
    getNextMin maxPoss = if maxPoss < 2 then 3 else maximum $ [x | x <- primes, x < maxPoss]

sieve :: [Int] -> [Int]
sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p /= 0]
sieve [] = []
