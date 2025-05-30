closestMeetingNode :: [Int] -> Int -> Int -> Int
closestMeetingNode edges node1 node2 = closestMeetingNode' edges node1 [] node2 []
  where
    closestMeetingNode' :: [Int] -> Int -> [Int] -> Int -> [Int] -> Int
    closestMeetingNode' edges node1 seen1 node2 seen2 =

-- 	seen1 := make(map[int]struct{})
-- 	seen2 := make(map[int]struct{})
-- 	curr1 := node1
-- 	curr2 := node2
-- 	for range len(edges) {
-- 		seen1[curr1] = struct{}{}
-- 		seen2[curr2] = struct{}{}
-- 		if _, found := seen1[curr2]; found {
-- 			if _, found := seen2[curr1]; found {
-- 				return min(curr1, curr2)
-- 			}
-- 			return curr2
-- 		}
-- 		if _, found := seen2[curr1]; found {
-- 			return curr1
-- 		}
-- 		if curr1 != -1 {
-- 			curr1 = edges[curr1]
-- 		}
-- 		if curr2 != -1 {
-- 			curr2 = edges[curr2]
-- 		}
-- 	}
-- 	return -1
-- }
