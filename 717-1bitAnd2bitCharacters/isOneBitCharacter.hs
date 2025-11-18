isOneBitCharacter :: [Int] -> Bool
isOneBitCharacter [] = False
isOneBitCharacter [0] = True
isOneBitCharacter (0 : xs) = isOneBitCharacter xs
isOneBitCharacter (1 : _ : xs) = isOneBitCharacter xs
