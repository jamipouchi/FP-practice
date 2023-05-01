"use strict";
// Functional approach
function average(salary) {
    return salary
        .sort((a, b) => a - b)
        .slice(1, -1)
        .reduce((a, b) => a + b) / (salary.length - 2);
}
;
// Imperative approach
function average(salary) {
    let min = salary[0];
    let max = salary[0];
    let sum = 0;
    for (const s of salary) {
        if (s < min)
            min = s;
        if (s > max)
            max = s;
        sum += s;
    }
    return (sum - min - max) / (salary.length - 2);
}
;
// test cases
console.log(average([4000, 3000, 1000, 2000])); // 2500
console.log(average([1000, 2000, 3000])); // 2000
