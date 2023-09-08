pascalTriangle :: [[Integer]]
pascalTriangle = [1] : map nextRow pascalTriangle
    where nextRow y = 1 : zipWith (+) y (tail y) ++ [1]

generate :: Int -> [[Integer]]
generate n = take n pascalTriangle
