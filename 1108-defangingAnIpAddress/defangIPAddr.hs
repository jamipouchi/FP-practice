defangIPAddress :: String -> String
defangIPAddress = concatMap fn
  where
    fn '.' = "[.]"
    fn c = [c]
