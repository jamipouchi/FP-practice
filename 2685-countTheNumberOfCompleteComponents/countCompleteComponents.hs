data UnionFindNode = UfNode {parent :: Int, edges :: Int} deriving (Eq)

newtype UnionFind = UnionFind [UnionFindNode]

makeSet :: Int -> UnionFind
makeSet n = UnionFind (map (\i -> UfNode {parent = i, edges = 0}) [0 .. n])

find :: UnionFind -> Int -> UnionFindNode
find uf@(UnionFind parents) x
  | parent (parents !! x) == x = parents !! x
  | otherwise = find uf $ parent (parents !! x)

union :: UnionFind -> Int -> Int -> UnionFind
union uf@(UnionFind parents) x y =
  let xRoot = find uf x
      yRoot = find uf y
   in if xRoot == yRoot
        then uf
        else
          UnionFind $
            map
              ( \i ->
                  if i == xRoot
                    then
                      UfNode {parent = parent yRoot, edges = 0}
                    else
                      if i == yRoot
                        then yRoot {edges = edges xRoot + edges yRoot + 1}
                        else i
              )
              parents

countCompleteComponents :: Int -> [[Int]] -> Int
countCompleteComponents n edges = undefined -- I got tired.
