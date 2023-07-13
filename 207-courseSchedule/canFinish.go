package courseschedule

func canFinish(numCourses int, prerequisites [][]int) bool {
	blocksCourses := make([][]int, numCourses)
	blockedBy := make([]int, numCourses)
	for _, pair := range prerequisites {
		blockedBy[pair[0]]++;
		blocksCourses[pair[1]] = append(blocksCourses[pair[1]], pair[0]);
	}
	Q := []int{}
	for course := 0; course < numCourses; course++ {
		if blockedBy[course] == 0 {
			Q = append(Q, course)
		}
	}
	coursesScheduled := 0
	for len(Q) > 0 {
		course := Q[0];
		Q = Q[1:]
		coursesScheduled++
		for _, blockedCourse := range blocksCourses[course] {
			blockedBy[blockedCourse]--
			if blockedBy[blockedCourse] == 0 {
				Q = append(Q, blockedCourse)
			}
		}
	}
	for _, numBlocks := range blockedBy {
		if numBlocks > 0 {
			return false
		}
	}
	return coursesScheduled == numCourses
}