data ListNode a = Node a (ListNode a) | Nil deriving (Show)

fromList :: [a] -> ListNode a
fromList = foldr Node Nil

splitListToParts :: ListNode a -> Int -> [ListNode a]
splitListToParts ll k = (\(f, _, _) -> f) $ helper ll 0 k
  where
    helper :: ListNode a -> Int -> Int -> ([ListNode a], Int, Int)
    helper Nil i k = ([Nil], i, 0)
    helper (Node v ns) i k
      | k' > totalLen =
          (Node v Nil : replicate (totalLen - k') Nil ++ c : ll, totalLen - 1, 0)
      | totalLen `div` k' > headLen = (Node v c : ll, totalLen, headLen + 1)
      | otherwise = (Nil : Node v c : ll, totalLen - headLen, 0)
      where
        (c : ll, totalLen, headLen) = helper ns (i + 1) k
        k' = k - (length ll - 1)

-- [1,2,3] k=5
--      i=3
-- [1,2] (3,Nil,Nil) 2 0
-- 2/3 = 0 => [1] (2,3,Nil,Nil)
-- [1] (2,3,Nil,Nil) 1 0
-- 1/2 = 0 => (1,2,3,Nil,Nil)

-- [1,2,3] [Nil] [Nil]
--     i=3 k'=3
-- len=3 -> 3/3 = 1 => [1,2] [3] [Nil] [Nil]
--

-- [1,2,3,4,5,6,7,8,9,10]
--                  i=10 k=3 len=10
--                  ([Nil],10,0) 10/3 = 3 -> 3 > 0
--                  ([10],10,1) 10/3 = 3 -> 3 > 1
--                  ([(9:10),10,2]) 10/3 = 3 > 2
--                  ([(8:9:10),10,3]) 10/3 = 3 = 3 -> split
--                  ([Nil,8:9:10],7,0)

-- [1,2,3,4,5,6,7] [8,9,10]
-- i = 6 k=3 len=10 -> 3 on right
-- 10/3 = 3 <= 3 => split
-- len/k
-- [1,2,3,4] [5,6,7] [8,9,10]
-- i=3 k=2 len=7 -> 3 on right
-- 7/2 = 3 <= 3 => split

-- but... [1,2,3,4,5] [6,7]
-- i = 4 k=2 len=7 -> 2 on right
-- 7/2 = 3 > 2 => no split.

-- [1,2,3]
-- i=2 k=5 len=3 -> 0 on right
-- 3/5 -> 0 <= 0 => split
-- [1,2,3]
-- i=2 k=4 len=3 -> 0 on right
-- 3/4 -> 0 <= 0 => split
-- [1,2,3]
-- i=2 k=3 len=3 -> 0 on right
-- 3/3 -> 1 > 0 => NO split
-- [1,2] [3]
-- i=1 k=3 len=3 -> 1 on right
-- 2/3 = 1 <=1 -> split
-- [1] [2] [3]
-- i=0 k=2 len=2 -> 1 on right
-- 2/2 = 1 <=1 -> split
