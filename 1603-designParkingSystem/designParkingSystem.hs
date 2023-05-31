data Capacity = Capacity Int Int deriving (Show)

data ParkingSystem = ParkingSystem {big :: Capacity, medium :: Capacity, small :: Capacity} deriving (Show)

newParkingSystem :: Int -> Int -> Int -> ParkingSystem
newParkingSystem big medium small = ParkingSystem (Capacity 0 big) (Capacity 0 medium) (Capacity 0 small)

data CarType = BIG | MEDIUM | SMALL deriving (Show, Enum)

addCar :: ParkingSystem -> CarType -> Maybe ParkingSystem
addCar (ParkingSystem (Capacity big_ava big_tot) _ _) BIG = if big_ava < big_tot then Just (ParkingSystem (Capacity (big_ava + 1) big_tot)) else Nothing
addCar (ParkingSystem _ (Capacity medium_ava medium_tot) _) MEDIUM = if medium_ava < medium_tot then Just (ParkingSystem (Capacity (medium_ava + 1) medium_tot)) else Nothing
addCar (ParkingSystem _ _ (Capacity small_ava small_tot)) SMALL = if small_ava < small_tot then Just (ParkingSystem (Capacity (small_ava + 1) small_tot)) else Nothing

-- and this is why lenses where invented