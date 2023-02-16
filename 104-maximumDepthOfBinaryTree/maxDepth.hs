data TreeNode = TreeNode Int TreeNode TreeNode | Null

new :: Int -> TreeNode
new x = TreeNode x Null Null

maxDepth :: TreeNode -> Int
maxDepth Null = 0
maxDepth (TreeNode _ l r) = 1 + max (maxDepth l) (maxDepth r)