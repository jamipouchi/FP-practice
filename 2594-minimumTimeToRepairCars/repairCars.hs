repairCars :: [Int] -> Int -> Int
repairCars ranks cars = binSearch (canRepair ranks cars) 0 (maximum ranks * cars * cars)
  where
    binSearch :: (Int -> Bool) -> Int -> Int -> Int
    binSearch p l r
      | l == r = l
      | otherwise =
          let m = (l + r) `div` 2
           in if p m
                then binSearch p l m
                else binSearch p (m + 1) r
    canRepair :: [Int] -> Int -> Int -> Bool
    canRepair ranks cars target = sum (map (\rank -> intSqrt (fromIntegral target / fromIntegral rank)) ranks) >= cars

intSqrt :: Float -> Int
intSqrt n = floor (sqrt n)

main :: IO ()
main = do
  let firstRes = repairCars [4, 2, 3, 1] 10
  print firstRes
  let secondRes = repairCars [5, 1, 8] 6
  print secondRes
