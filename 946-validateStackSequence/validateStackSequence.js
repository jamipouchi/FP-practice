"use strict";
function validateStackSequences(pushed, popped) {
    const stack = [];
    let pushedIdx = 0;
    let poppedIdx = 0;
    while (pushedIdx < pushed.length) {
        stack.push(pushed[pushedIdx++]);
        while (stack.length > 0 && stack[stack.length - 1] === popped[poppedIdx]) {
            stack.pop();
            poppedIdx++;
        }
    }
    return stack.length === 0;
}
;
// tests
console.log(validateStackSequences([1, 2, 3, 4, 5], [4, 5, 3, 2, 1]) === true);
console.log(validateStackSequences([1, 2, 3, 4, 5], [4, 3, 5, 1, 2]) === false);
