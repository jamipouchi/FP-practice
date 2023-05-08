"use strict";
function diagonalSum(mat) {
    let diagonalSum = 0;
    // top half
    let row = 0;
    while (row < Math.floor(mat.length / 2)) {
        diagonalSum += mat[row][row] + mat[row][mat.length - 1 - row];
        row++;
    }
    // middle row (if it exists)
    if (mat.length % 2 === 1) {
        diagonalSum += mat[row][row];
        row++;
    }
    // bottom half
    while (row < mat.length) {
        diagonalSum += mat[row][row] + mat[row][mat.length - 1 - row];
        row++;
    }
    return diagonalSum;
}
;
// tests
console.log(diagonalSum([[1, 2, 3], [4, 5, 6], [7, 8, 9]])); // 25
console.log(diagonalSum([[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]])); // 8
console.log(diagonalSum([[5]])); // 5
