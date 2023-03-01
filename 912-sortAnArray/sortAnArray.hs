qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (p : xs) = qsort smaller ++ [p] ++ qsort greater
  where
    smaller = [x | x <- xs, x < p]
    greater = [x | x <- xs, x >= p]
