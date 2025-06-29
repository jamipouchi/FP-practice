import Control.Parallel.Strategies (parListChunk, parMap, rseq, using, withStrategy)
import Data.Bits (shiftL)
import Data.List (sort)

numSubseq :: [Int] -> Int -> Int
numSubseq = numSubseqSorted

numSubseqSorted :: [Int] -> Int -> Int
numSubseqSorted xs target = count target $ sort xs -- O(NlogN)
  where
    count :: Int -> [Int] -> Int
    count target [] = 0
    count target (x : xs) | 2 * x > target = 0 -- we know it's sorted, so we can stop
    count target (x : xs) = currCount + count target subArr
      where
        subArr = takeWhile (\b -> x + b <= target) xs
        currCount = (1 `shiftL`) $ length subArr

-- Improved by asking gpt to be more Haskelly. Mainly takeWhile and recursion changed by explicitely keeping l, r
-- Tbh, easier to read.
numSubseqSorted' :: [Int] -> Int -> Int
numSubseqSorted' xs target = go 0 (length sorted - 1)
  where
    sorted = sort xs
    go l r
      | l > r = 0
      | sorted !! l + sorted !! r <= target = (1 `shiftL` (r - l)) + go (l + 1) r
      | otherwise = go l (r - 1)

-- combinations (n+1)
-- combinations 1 = 1 -- 2^0
-- combinations 2 = 2 -- 2^1
-- combinations 3 = 4 -- 2^2
-- combinations 4 = 8 -- 2^3 [1,2,3,4] => [1], [1,2], [1,3], [1,4], [1,2,3], [1,2,4], [1,3,4], [1,2,3,4]
-- combinations 5 = 16 -- 2^3 [1,2,3,4,5] => [1], [1,2], [1,3], [1,4], [1,5], [1,2,3], [1,2,4], [1,2,5], [1,3,4], [1,3,5], [1,4,5], [1,2,3,4], [1,2,3,5], [1,2,4,5], [1,3,4,5], [1,2,3,4,5]
--
-- combinations of 1 number + combinations of 2 + combinations of 3 ... binomial coefficient
-- sum from i = 0 to n of (n choose i)

-- i = 0; move j as far to the right as possible => count all combinations THAT USE i (others will be accounted for later)
-- i = 1; move j as far to the right as possible => ...
-- i = 2; move j as far to the right as possible => ...
-- ...

-- nums=[3,5,6,7]; target=9
-- sorted => [3,5,6,7]
-- => #comb [3,5,6] + #comb [5,6] +#comb [6]
--
-- [3] fits
-- [3,5] fits
-- [3,5,6] fits
-- nums=[3,3,6,8]; target=10
-- sorted => [3,3,6,8]
-- [3,3,6] fits
-- [3,6] fits

-- Could do 2 pointer approach. i,j
-- #comb (i,j+1) = #comb(i,j)+1
-- needs to be n^2

numSubseqBrute :: [Int] -> Int -> Int
numSubseqBrute xs target = length $ filter (\arr -> minimum arr + maximum arr <= target) $ init $ generateAllSubsequences xs
  where
    generateAllSubsequences [] = [[]] -- use it with init to avoid empty list
    generateAllSubsequences (x : xs) = map (x :) generatedWithoutX ++ generatedWithoutX
      where
        generatedWithoutX = generateAllSubsequences xs

-- numSubseqBruteP :: [Int] -> Int -> Int
-- numSubseqBruteP xs target = length $ filter (\arr -> minimum arr + maximum arr <= target) $ init $ generateAllSubsequencesP xs
--   where
--     generateAllSubsequencesP = runPar
--     generateAllSubsequences [] = [[]] -- use it with init to avoid empty list
--     generateAllSubsequences (x : xs) = x `consAll` generatedWithoutX ++ generatedWithoutX
--       where
--         consAll :: a -> [[a]] -> [[a]]
--         consAll x [v] = [x : v]
--         consAll x (v : vs) = (x : v) : consAll x vs
--         generatedWithoutX = generateAllSubsequences xs

-- Instead of picking or not picking a value, it adds or does not add a value
generateAllSubsequences :: [a] -> [[a]]
generateAllSubsequences = foldr step [[]]
  where
    step x acc =
      let withX = map (x :) acc
       in (withX `using` parListChunk 25 rseq) ++ acc

main :: IO ()
main = do
  print $ generateAllSubsequences [1 .. 25]
  return ()

-- [a,b,c,d]
-- [[d]] + [[]]
-- [[c]] + [[]]
-- ..
-- ..

-- You are given an array of integers nums and an integer target.

-- Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

-- Example 1:

-- Input: nums = [3,5,6,7], target = 9
-- Output: 4
-- Explanation: There are 4 subsequences that satisfy the condition.
-- [3] -> Min value + max value <= target (3 + 3 <= 9)
-- [3,5] -> (3 + 5 <= 9)
-- [3,5,6] -> (3 + 6 <= 9)
-- [3,6] -> (3 + 6 <= 9)
-- Example 2:

-- Input: nums = [3,3,6,8], target = 10
-- Output: 6
-- Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
-- [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
-- Example 3:

-- Input: nums = [2,3,3,4,6,7], target = 12
-- Output: 61
-- Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
-- Number of valid subsequences (63 - 2 = 61).
