kidsWithCandies :: [Int] -> Int -> [Bool]
kidsWithCandies candies extraCandies = map (\x -> x + extraCandies >= maxCandies) candies
    where maxCandies = maximum candies

-- tests

test1 :: Bool
test1 = kidsWithCandies [2,3,5,1,3] 3 == [True,True,True,False,True]

test2 :: Bool
test2 = kidsWithCandies [4,2,1,1,2] 1 == [True,False,False,False,False]

test3 :: Bool
test3 = kidsWithCandies [12,1,12] 10 == [True,False,True]

runTests :: IO ()
runTests = do
    print test1
    print test2
    print test3