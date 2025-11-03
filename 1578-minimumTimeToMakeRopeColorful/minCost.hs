minCost :: String -> [Int] -> Int
minCost [] [] = 0
minCost [color] [cost] = 0
minCost (color1 : color2 : colors) (cost1 : cost2 : costs)
  | color1 == color2 =
      if cost1 < cost2
        then cost1 + minCost (color2 : colors) (cost2 : costs)
        else cost2 + minCost (color2 : colors) (cost1 : costs)
  | otherwise = minCost (color2 : colors) (cost2 : costs)
