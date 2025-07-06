import Data.IntMap qualified as M

data FindSumPairs = FindSumPairs {nums1, nums2 :: [Int], hm2 :: M.IntMap Int}

new :: [Int] -> [Int] -> FindSumPairs
new nums1 nums2 = FindSumPairs {nums1, nums2, hm2}
  where
    hm2 = M.fromListWith (+) [(x, 1) | x <- nums2]

add :: FindSumPairs -> Int -> Int -> FindSumPairs
add fsp@FindSumPairs {hm2, nums2} index val =
  let toDecrease = nums2 !! index
      newNums2 = take index nums2 ++ [toDecrease + val] ++ drop (index + 1) nums2
      newHm2 = M.adjust (\x -> x - 1) toDecrease $ M.insertWith (+) (toDecrease + val) 1 hm2
   in fsp {nums2 = newNums2, hm2 = newHm2}

count :: FindSumPairs -> Int -> Int
count FindSumPairs {nums1, hm2} tot =
  sum [M.findWithDefault 0 (tot - v) hm2 | v <- nums1]
