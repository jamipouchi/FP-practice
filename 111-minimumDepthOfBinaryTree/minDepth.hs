data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Show, Eq)

minDepthDFS :: Tree a -> Int
minDepthDFS Empty = 0
minDepthDFS (Node _ Empty Empty) = 1
minDepthDFS (Node _ Empty right) = 1 + minDepthDFS right
minDepthDFS (Node _ left Empty) = 1 + minDepthDFS left
minDepthDFS (Node _ left right) = 1 + min (minDepthDFS left) (minDepthDFS right)

-- THIS IS INCORRECT!!
minDepthBFS :: Eq a => Tree a -> Int
minDepthBFS Empty = 0
minDepthBFS tree = layers 1 [Just tree]
  where
    layers n [] = n
    layers n xs =
      if Nothing `elem` xs
        then n
        else layers (n + 1) (concatMap (foldMap children) xs)
    children (Node _ Empty Empty) = [Nothing] -- this should end
    children (Node _ left Empty) = [Just left]
    children (Node _ Empty right) = [Just right]
    children (Node _ left right) = [Just left, Just right]
    children Empty = error "Unreachable"

main = do
  let tree = Node 1 (Node 2 (Node 4 Empty Empty) (Node 5 Empty Empty)) (Node 3 Empty Empty)
  print $ minDepthDFS tree
  print $ minDepthBFS tree