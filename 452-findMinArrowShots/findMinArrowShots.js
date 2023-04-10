"use strict";
const findMinArrowShots = (points) => {
    const sorted = points.sort((left, right) => left[0] === right[0] ? left[1] - right[1] : left[0] - right[0]);
    return countArrows(sorted[0][1], sorted);
};
const countArrows = (lastPoint, points) => points.length === 0
    ? 1
    : points[0][0] > lastPoint
        ? 1 + countArrows(points[0][1], points.slice(1))
        : countArrows(min(lastPoint, points[0][1]), points.slice(1));
const min = (a, b) => a < b ? a : b;
// This solution doesn't pass Leetcode due to memory allocation, as each new slice creates a new array :(
// We can go through by using a ptr to the non-visited element.
const findMinArrowShots_with_ptr = (points) => {
    const sorted = points.sort((left, right) => left[0] === right[0] ? left[1] - right[1] : left[0] - right[0]);
    return countArrows_with_ptr(sorted[0][1], sorted, 1);
};
const countArrows_with_ptr = (lastPoint, points, idx) => {
    return idx === points.length
        ? 1
        : points[idx][0] > lastPoint
            ? 1 + countArrows_with_ptr(points[idx][1], points, idx + 1)
            : countArrows_with_ptr(min(lastPoint, points[idx][1]), points, idx + 1);
};
console.log(findMinArrowShots_with_ptr([[10, 16], [2, 8], [1, 6], [7, 12]]), " =? 2");
console.log(findMinArrowShots_with_ptr([[1, 2], [3, 4], [5, 6], [7, 8]]), " =? 4");
console.log(findMinArrowShots_with_ptr([[1, 2], [2, 3], [3, 4], [4, 5]]), " =? 2");
console.log(findMinArrowShots_with_ptr([[9, 12], [1, 10], [4, 11], [8, 12], [3, 9], [6, 9], [6, 7]]), " =? 2");
