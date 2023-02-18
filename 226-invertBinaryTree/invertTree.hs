data BinTree = Node Int BinTree BinTree | Null deriving (Show)

invertTree :: BinTree -> BinTree
invertTree Null = Null
invertTree (Node v l r) = Node v (invertTree r) (invertTree l)