data TreeNode = TreeNode Int (Maybe TreeNode) (Maybe TreeNode)

new :: Int -> TreeNode
new x = TreeNode x Nothing Nothing

maxDepth :: Maybe TreeNode -> Int
maxDepth Nothing = 0
maxDepth (Just (TreeNode _ l r)) = 1 + max (maxDepth l) (maxDepth r)