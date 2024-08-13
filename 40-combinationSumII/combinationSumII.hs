import Control.Arrow
import Data.List
import Data.Ord

sortByLen :: (Ord a) => [[a]] -> [[a]]
sortByLen = map snd . sort . map (length &&& id)

dedup :: [[Int]] -> [[Int]]
dedup = map head . group . sortByLen . map sort

combinationSumII :: [Int] -> Int -> [[Int]]
combinationSumII a b = dedup $ combinationSumII' [] a b

combinationSumII' :: [Int] -> [Int] -> Int -> [[Int]]
combinationSumII' _ [] target = []
combinationSumII' curr (c : cs) target
  | sum curr + c == target = (c : curr) : combinationSumII' curr cs target
  | sum curr + c > target = combinationSumII' curr cs target
  | sum curr + c < target = combinationSumII' (c : curr) cs target ++ combinationSumII' curr cs target
