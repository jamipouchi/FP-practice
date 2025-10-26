newtype Bank = Bank [Integer]

bankCreate :: [Integer] -> Bank
bankCreate = Bank

validateAccount :: Bank -> Int -> Bool
validateAccount (Bank accounts) accNum =
  accNum >= 1 && accNum <= length accounts

sufficientFunds :: Bank -> Int -> Integer -> Bool
sufficientFunds (Bank accounts) accNum = (>=) $ accounts !! accNum - 1

addTo :: [Integer] -> Int -> Integer -> [Integer]
addTo accounts accNum amount =
  let (before, x : after) = splitAt (accNum - 1) accounts
   in before ++ (x + amount) : after

withdrawFrom :: [Integer] -> Int -> Integer -> [Integer]
withdrawFrom accounts accNum amount = addTo accounts accNum (-amount)

bankTransfer :: Bank -> Int -> Int -> Integer -> (Bool, Bank)
bankTransfer (Bank accounts) acc1 acc2 amount
  | not (validateAccount (Bank accounts) acc1) || not (validateAccount (Bank accounts) acc2) = (False, Bank accounts)
  | not (sufficientFunds (Bank accounts) acc1 amount) = (False, Bank accounts)
  | otherwise =
      let updatedAccounts = do
            let afterWithdraw = withdrawFrom accounts acc1 amount
            addTo afterWithdraw acc2 amount
       in (True, Bank updatedAccounts)

bankDeposit :: Bank -> Int -> Integer -> (Bool, Bank)
bankDeposit (Bank accounts) accNum amount
  | not (validateAccount (Bank accounts) accNum) = (False, Bank accounts)
  | otherwise =
      let updatedAccounts = addTo accounts accNum amount
       in (True, Bank updatedAccounts)

bankWithdraw :: Bank -> Int -> Integer -> (Bool, Bank)
bankWithdraw (Bank accounts) accNum amount
  | not (validateAccount (Bank accounts) accNum) = (False, Bank accounts)
  | not (sufficientFunds (Bank accounts) accNum amount) = (False, Bank accounts)
  | otherwise =
      let updatedAccounts = withdrawFrom accounts accNum amount
       in (True, Bank updatedAccounts)
