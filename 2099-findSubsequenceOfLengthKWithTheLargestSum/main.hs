import Data.Heap qualified as H -- (MinPrioHeap)
import Data.List (sortBy)
import Data.Maybe (fromJust)

type MinHeap = H.MinPrioHeap Int Int -- (value, index)

maxSubsequence :: [Int] -> Int -> [Int]
maxSubsequence xs k = map fst $ sortBy indexSort $ H.toList $ makeHeap xs k
  where
    makeHeap :: [Int] -> Int -> MinHeap
    makeHeap xs k = foldl insertItem emptyHeap (zip xs [0 ..])
      where
        emptyHeap = H.empty :: MinHeap
        insertItem h (x, i) = if H.size heapWithItem <= k then heapWithItem else fromJust (H.viewTail heapWithItem)
          where
            heapWithItem = H.insert (x, i) h

    indexSort :: (Int, Int) -> (Int, Int) -> Ordering
    indexSort (_, i1) (_, i2) = compare i1 i2

main :: IO ()
main = do
  print $ maxSubsequence [2, 1, 3, 3] 2
  print $ maxSubsequence [-1, -2, 3, 4] 3
  print $ maxSubsequence [3, 4, 3, 3] 2
  print $ maxSubsequence [-56, -214, -345, 952, 529, -294, -325, -924, -27, -41, 716, -67, -65, -481] 5
