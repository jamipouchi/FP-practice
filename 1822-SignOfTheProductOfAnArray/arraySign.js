"use strict";
// Functional approach
/* function arraySign(nums: number[]): number {
    return nums.reduce((sign, num) => {
        if (num === 0) {
            return 0
        }
        return sign * (num > 0 ? 1 : -1)
    }, 1);
} */
// Imperative approach
function arraySign(nums) {
    let sign = 1;
    for (const num of nums) {
        if (num === 0) {
            return 0;
        }
        sign *= num > 0 ? 1 : -1;
    }
    return sign;
}
// tests
console.log(arraySign([-1, -2, -3, -4, 3, 2, 1])); // 1
console.log(arraySign([1, 5, 0, 2, -3])); // 0
console.log(arraySign([-1, 1, -1, 1, -1])); // -1
