isValid :: String -> Bool
isValid [] = True
isValid (p : ps) = isOpen p && closes p p' && isValid ps'
  where
    (p' : ps') = getNext ps

getNext :: String -> String
getNext [] = ""
getNext (p : ps) = if isOpen p && closes p p' then getNext ps' else p : ps
  where
    (p' : ps') = getNext ps

isOpen :: Char -> Bool
isOpen '(' = True
isOpen '[' = True
isOpen '{' = True
isOpen _ = False

closes :: Char -> Char -> Bool
closes '(' ')' = True
closes '[' ']' = True
closes '{' '}' = True
closes _ _ = False

-- tests

test1 = isValid "()" == True
test2 = isValid "([])" == True
test3 = isValid "([)]" == False
test4 = isValid "([{}])" == True

-- main
main :: IO ()
main = do
  print test1
  print test2
  print test3
  print test4