import Data.List
import Data.Maybe

lemonadeCost :: Int
lemonadeCost = 5

lemonadeChange :: [Int] -> Bool
lemonadeChange bills = isJust $ foldl handlePayment (Just []) bills
  where
    handlePayment :: Maybe [Int] -> Int -> Maybe [Int]
    handlePayment Nothing _ = Nothing
    handlePayment (Just availableMoney) payment =
      giveBack (payment - lemonadeCost) availableMoney >>= \remainingBills -> Just (insertOrdered payment remainingBills)

giveBack :: Int -> [Int] -> Maybe [Int]
giveBack 0 bills = Just bills
giveBack _ [] = Nothing
giveBack amount (bill : bills)
  | amount == bill = Just bills
  | amount > bill = giveBack (amount - bill) bills
  | amount < bill = giveBack amount bills >>= \remainingBills -> Just (bill : remainingBills)

insertOrdered :: (Ord a) => a -> [a] -> [a]
insertOrdered x [] = [x]
insertOrdered x (b : bs)
  | x >= b = x : b : bs
  | otherwise = b : insertOrdered x bs
