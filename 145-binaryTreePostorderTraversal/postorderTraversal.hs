data TreeNode = Nil | Branch Int TreeNode TreeNode deriving (Show)

postorderTraversal :: TreeNode -> [Int]
postorderTraversal Nil = []
postorderTraversal (Branch x l r) = postorderTraversal r ++ postorderTraversal l ++ [x]
