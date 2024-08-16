import Control.Arrow

data MinMaxState = MinMax
  { minV :: Int,
    maxV :: Int,
    same :: Bool,
    sndMin :: Int,
    sndMax :: Int
  }
  deriving (Show)

initialState :: MinMaxState
initialState = MinMax {minV = maxBound, maxV = minBound, same = False, sndMin = maxBound, sndMax = minBound}

maxDistance :: [[Int]] -> Int
maxDistance values = maxDiffFromState $ foldl updateState initialState $ map (minimum &&& maximum) values

maxDiffFromState :: MinMaxState -> Int
maxDiffFromState MinMax {minV, maxV, same = False} = maxV - minV
maxDiffFromState MinMax {minV, maxV, sndMin, sndMax} = min (maxV - sndMin) (sndMax - minV)

updateState :: MinMaxState -> (Int, Int) -> MinMaxState
updateState MinMax {minV, maxV, same, sndMin, sndMax} (cMin, cMax)
  | cMin < minV && cMax > maxV = MinMax {minV = cMin, maxV = cMax, same = True, sndMin = minV, sndMax = maxV}
  | cMin < minV = MinMax {minV = cMin, maxV, same = False, sndMin = minV, sndMax}
  | cMax > maxV = MinMax {minV, maxV = cMax, same = False, sndMin, sndMax = maxV}
  | cMin < sndMin || cMax > sndMax = MinMax {minV, maxV, same, sndMin = min sndMin cMin, sndMax = max sndMax cMax}
  | otherwise = MinMax {minV, maxV, same, sndMin, sndMax}

{-
    What's the rule of being able to pick a number
    (min, max) => We always pick min iff min is the minimum and max is not the (only) maximum (same for max)
    // What if it's both the minimum and the maximum? (That's the only case we should worry about!)
    => Simply find the next minimum maximum, and return!

    (1,5) minimum and not maximum => (1,X)
    (2,3)
    (3,8) maximum and not minimum => (X,8)

    => (1,8)

    (1,5) only minimum and only maximum. Find next min/max
    (2,3) => next min is 2
    (2,4) => next max is 4
    => result is either (1,4) | (2,5)
-}
