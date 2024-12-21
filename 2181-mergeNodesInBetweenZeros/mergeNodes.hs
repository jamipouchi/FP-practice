data ListNode a = Node a (ListNode a) | Nil deriving (Show)

mergeNodes :: ListNode Int -> ListNode Int
mergeNodes Nil = Nil
mergeNodes (Node a nextNode) = mergeNodes' 0 nextNode
  where
    mergeNodes' :: Int -> ListNode Int -> ListNode Int
    mergeNodes' cum Nil = Nil
    mergeNodes' cum (Node val nextNode)
      | val == 0 = Node cum (mergeNodes' 0 nextNode)
      | otherwise = mergeNodes' (cum + val) nextNode

test = do
  let example1 = Node 0 (Node 3 (Node 1 (Node 0 (Node 4 (Node 5 (Node 2 (Node 0 Nil)))))))
  let result1 = mergeNodes example1
  print result1 -- Node 4 (Node 11 Nil)
  let example2 = Node 0 (Node 1 (Node 0 (Node 3 (Node 0 (Node 2 (Node 2 (Node 0 Nil)))))))
  let result2 = mergeNodes example2
  print result2
