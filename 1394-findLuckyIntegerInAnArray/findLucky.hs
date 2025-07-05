import Data.List qualified as List
import Data.Map qualified as Map
import Data.Maybe (fromMaybe)

-- Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

-- Return the largest lucky integer in the array. If there is no lucky integer return -1.

findLucky :: [Int] -> Int
findLucky = fromMaybe (-1) . safeMaximum . map fst . filter (uncurry (==)) . Map.toList . buildMap
  where
    buildMap :: [Int] -> Map.Map Int Int
    buildMap = foldr (\v m -> Map.insertWith (+) v 1 m) Map.empty
    safeMaximum :: [Int] -> Maybe Int
    safeMaximum [] = Nothing
    safeMaximum xs = Just $ List.maximum xs

{--
 - Instead of fromMaybe (-1) . safeMaximum, we could simply maximumOr-1, sth like : maxiumOr-1 xs = List.maximum (-1: xs)
 --}
