detectCapital :: String -> Bool
--detectCapital = or . (<*>) [all uppercase, all lowercase, (&&) . (uppercase . head) <*> (all lowercase . tail)] . (: [])
-- No need for lambda :)
-- Thought the better bersion is
detectCapital = (||) . all uppercase <*> (all lowercase . tail)

uppercase :: Char -> Bool
uppercase = (&&) . (<= 'Z') <*> (>= 'A')

lowercase :: Char -> Bool
lowercase = (&&) . (<= 'z') <*> (>= 'a')