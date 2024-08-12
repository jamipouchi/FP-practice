data KthSmallest = KthSmallest Int [Int] deriving (Show)

sort :: [Int] -> [Int]
sort [] = []
sort (x : xs) = sort [y | y <- xs, y <= x] ++ [x] ++ sort [y | y <- xs, y > x] -- Quicksort

kthSmallest :: Int -> [Int] -> KthSmallest
kthSmallest k xs = KthSmallest k (reverse $ take k (sort xs))

-- For efficiency we store it reversed

addKth :: KthSmallest -> Int -> (KthSmallest, Int)
addKth (KthSmallest k (x : xs)) y
  -- base case
  | x <= y = (KthSmallest k (x : xs), x)
  | otherwise = (KthSmallest k (h : r), h)
  where
    (h : r) = insert xs y

insert :: [Int] -> Int -> [Int]
insert [] y = [y]
insert (x : xs) y
  | y >= x = y : x : xs
  | otherwise = x : insert xs y

-- Tests

instructions :: ((Int, [Int]), [Int])
instructions = ((3, [4, 5, 8, 2]), [3, 5, 10, 9, 4])

runInstructions ((k, initialList), adds) = runAdds (kthSmallest k initialList) adds

runAdds :: KthSmallest -> [Int] -> [(KthSmallest, Int)]
runAdds kth [] = []
runAdds kth (add : adds) = (kth', a) : runAdds kth' adds
  where
    (kth', a) = addKth kth add

main :: IO ()
main = do
  let kth = kthSmallest 3 [4, 5, 8, 2]
  print kth
  let (kth, a) = addKth kth 3
  print kth
  print a
  let (kth, a) = addKth kth 5
  print kth
  print a
  let (kth, a) = addKth kth 10
  print kth
  print a
  let (kth, a) = addKth kth 9
  print kth
  print a
  let (kth, a) = addKth kth 4
  print kth
  print a
  return ()
