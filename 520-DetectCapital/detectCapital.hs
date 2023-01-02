detectCapital :: String -> Bool
detectCapital = or . (\x -> map ($ x) [all uppercase, all lowercase, (&&) . (uppercase . head) <*> (all lowercase . tail)])

-- I bet the lambda can be done better. There exists a combinator lens (??) which does that, but I don't know how to build it point free.

uppercase :: Char -> Bool
uppercase = (&&) . (<= 'Z') <*> (>= 'A')

lowercase :: Char -> Bool
lowercase = (&&) . (<= 'z') <*> (>= 'a')
