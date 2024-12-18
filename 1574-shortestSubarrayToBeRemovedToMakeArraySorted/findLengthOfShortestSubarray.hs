findLengthOfShortestSubarray :: [Int] -> [Int]
findLengthOfShortestSubarray array = undefined

{-
    [1,2,3,10,4,2,3,5]
    123(10)
    1234 // what do we do here??
    we split:
    - 122 -> 1223 -> 12235
    - 1233 -> 12335
-}

{-
    [1,2,3,10,4,2,4,5]
    123(10)
    1234 // what do we do here??

    we split:
    - 122 -> 1224 -> 12245
    - 12344 -> 123445
-}

{-
    [5,4,3,2,1]
    5
    4
    3
    2
    !1

    [1,4,3,2,1]
    1
    14
    13
    12
    11

-}
