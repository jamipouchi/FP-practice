import Data.List (sortBy)

--
-- The strategy is quite simple: greedy match.

matchPlayersAndTrainers :: [Int] -> [Int] -> Int
matchPlayersAndTrainers players trainers = greedyMatch (sortBy (flip compare) players) (sortBy (flip compare) trainers)
  where
    greedyMatch :: [Int] -> [Int] -> Int
    greedyMatch [] _ = 0
    greedyMatch _ [] = 0
    greedyMatch (p : ps) (t : ts) =
      if p > t
        then 0 + greedyMatch ps (t : ts)
        else 1 + greedyMatch ps ts
