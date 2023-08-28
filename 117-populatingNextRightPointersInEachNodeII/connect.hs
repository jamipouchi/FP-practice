data Node = Node Int Node Node Node | Nil deriving (Show, Eq)
--               Val Left Right Next

-- I don't know how to get back the root xd!
connect :: Node -> [Node]
connect Nil = []
connect root = connectLayer [root]

connectLayer :: [Node] -> [Node]
connectLayer [] = []
connectLayer [Node val Nil Nil Nil] = [Node val Nil Nil Nil]
connectLayer [Node val l Nil Nil] = connectLayer [l]
connectLayer [Node val Nil r Nil] = connectLayer [r]
connectLayer ((Node val l r _) : c) = connectLayer $ sons $ connectNext $ Node val l r (head c) : connectLayer c

connectNext :: [Node] -> [Node]
connectNext [] = []
connectNext [Node val Nil Nil Nil] = [Node val Nil Nil Nil]
connectNext ((Node val l r n) : c) = Node val l r (head c) : connectNext c

sons :: [Node] -> [Node]
sons [] = []
sons ((Node _ Nil Nil _) : c) = sons c
sons ((Node _ l Nil _) : c) = l : sons c
sons ((Node _ Nil r _) : c) = r : sons c
sons ((Node _ l r _) : c) = l : r : sons c

main = print $ connect (Node 
    1 
    (Node 2 (Node 4 Nil Nil Nil) (Node 5 Nil Nil Nil) Nil) 
    (Node 3 Nil (Node 7 Nil Nil Nil) Nil)
    Nil)