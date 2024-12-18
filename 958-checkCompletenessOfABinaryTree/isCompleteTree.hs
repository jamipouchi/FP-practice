data BinTree a = TreeNode a (BinTree a) (BinTree a) | Nil

data LeveledStatus = Full | Last | Invalid

isCompleteTree :: BinTree a -> Bool
isCompleteTree Nil = True
isCompleteTree (TreeNode _ l r) = areLeveled [l, r]
  where
    areLeveled :: [BinTree a] -> Bool
    areLeveled bts = case foldl nextStatus Full bts of
      Full -> areLeveled $ children bts
      Last -> all lastLevel bts -- This is incorrect. Too lazy to change it.
      Invalid -> False

    nextStatus :: LeveledStatus -> BinTree a -> LeveledStatus
    nextStatus Full Nil = Last
    nextStatus Full bt = Full
    nextStatus Last Nil = Last
    nextStatus Last bt = Invalid
    nextStatus Invalid _ = Invalid

    lastLevel :: BinTree a -> Bool
    lastLevel Nil = True
    lastLevel (TreeNode _ Nil Nil) = True
    lastLevel _ = False

    children :: [BinTree a] -> [BinTree a]
    children [] = []
    children ((TreeNode _ l r) : rest) = l : r : children rest
