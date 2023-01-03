import Data.List (transpose)

minDeletionSize :: [String] -> Int
minDeletionSize = length . filter (not . sorted) . transpose
  where
    sorted = and . (zipWith (<=) <*> tail)