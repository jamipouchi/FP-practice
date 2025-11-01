modifiedList :: [Int] -> [Int] -> [Int]
modifiedList nums head = [x | x <- head, x `notElem` nums]
