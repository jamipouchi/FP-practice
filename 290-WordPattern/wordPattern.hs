wordPattern :: String -> String -> Bool
wordPattern [] [] = True
wordPattern [] _ = False
wordPattern _ [] = False
wordPattern (p : pRest) w = (map (== p) pRest == map (== s) sRest) && wordPattern (filter (== p) pRest) (unwords $ filter (== s) sRest)
  where
    (s : sRest) = words w