import Data.Foldable (maximumBy)

minTaps :: Int -> [Int] -> Int
minTaps n ranges = countTaps (mapIndexed (\i r -> (i - r, i + r)) ranges) 0 n

countTaps :: [(Int, Int)] -> Int -> Int -> Int
countTaps ranges idx n
  | null ranges = -1
  | idx >= n = 0
  | otherwise = if cost == -1 then -1 else 1 + cost
  where
    cost = countTaps nextRanges nextIdx n
    (nextRanges, nextIdx) = calculateNext (ranges, idx)

calculateNext :: ([(Int, Int)], Int) -> ([(Int, Int)], Int)
calculateNext (ranges, idx) = if not (null taken) then (nextRanges, snd $ maximumBy (\(_, s1) (_, s2) -> compare s1 s2) taken) else ([], 0)
  where
    (taken, nextRanges) = span (\(s, _) -> s < idx) ranges

mapIndexed :: (Int -> a -> b) -> [a] -> [b]
mapIndexed pred = mapWithIndex 0
  where
    mapWithIndex idx (l : ls) = pred idx l : mapWithIndex (idx + 1) ls
    mapWithIndex _ [] = []

main :: IO ()
main = do
  print $ show (minTaps 5 [3, 4, 1, 1, 0, 0]) ++ " == 1"
  print $ show (minTaps 3 [0, 0, 0, 0]) ++ " == -1"
