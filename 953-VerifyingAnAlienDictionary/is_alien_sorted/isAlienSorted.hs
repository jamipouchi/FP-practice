isAlienSorted :: [String] -> String -> Bool
isAlienSorted words order = all ordered $ zip words (tail words)
  where
    ordered ([], bs) = True
    ordered (as, []) = False
    ordered (a : as, b : bs) =
      if a == b
        then ordered (as, bs)
        else position a order < position b order
    position :: Char -> String -> Int
    position c = length . takeWhile (/= c)