import Data.Map (Map, empty, lookup)
import Data.Map.Strict (foldrWithKey, insertWith)
import Prelude hiding (lookup)

checkInclusion :: String -> String -> Bool
checkInclusion sub (s : ss) =
  length ss >= len1
    && (chars sub `equalChars` chars (s : take len1 ss) || checkInclusion sub ss)
  where
    len1 = length sub - 1
    isPermutation :: String -> String -> Bool
    isPermutation s1 s2 = chars s1 `equalChars` chars s2

type Chars = Map Char Int

chars :: String -> Chars
chars = foldl (\m k -> insertWith (+) k 1 m) empty

equalChars :: Chars -> Chars -> Bool
equalChars ch1 ch2 = foldrWithKey (\k v b -> b && (lookup k ch2 == Just v)) True ch1
