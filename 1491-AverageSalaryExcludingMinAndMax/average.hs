average :: [Int] -> Float
average salary = fromIntegral (sum salary - maximum salary - minimum salary) / fromIntegral (length salary - 2)