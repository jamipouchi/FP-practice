areSentencesSimilar :: String -> String -> Bool
areSentencesSimilar s1 s2 = uncurry eitherEmpty $ uncurry removeSuffix $ removePrefix s1 s2

removeSuffix :: String -> String -> (String, String)
removeSuffix a b = (\(a, b) -> (reverse a, reverse b)) $ removePrefix (reverse a) (reverse b)

removePrefix :: String -> String -> (String, String)
removePrefix [] rst = ([], rst)
removePrefix rst [] = (rst, [])
removePrefix (a : as) (b : bs)
  | a == b = removePrefix as bs
  | otherwise = (a : as, b : bs)

eitherEmpty :: String -> String -> Bool
eitherEmpty [] _ = True
eitherEmpty _ [] = True
eitherEmpty _ _ = False

{-
    Two sentences are similar iff one is contained inside the other in a prefix/suffix way
    (NOTE: I am not checking spaces)
-}
