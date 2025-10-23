import Data.Char (digitToInt, intToDigit)

hasSameDigits :: String -> Bool
hasSameDigits [a, b] = a == b
hasSameDigits (x : xs) =
  hasSameDigits $ zipWith (\a b -> intToDigit $ (digitToInt a + digitToInt b) `mod` 10) (x : xs) xs
