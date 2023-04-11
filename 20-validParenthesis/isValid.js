"use strict";
/* // imperative, with a stack

function isValid(s: string): boolean {
    if (s.length == 0) {
        return true;
    }
    if (s.length % 2 !== 0) {
        return false;
    }
    const stack : string[] = [];
    let ptr: number = 0;
    while (ptr < s.length) {
        const top = stack[stack.length - 1];
        if (closes(top, s[ptr])) {
            stack.pop();
        }
        else {
            stack.push(s[ptr]);
        }
        ptr++;
    }
    return stack.length === 0;
}
*/
// functional, with recursion
// This actually performs better than the imperative version
function isValid(s) {
    if (s.length == 0) {
        return true;
    }
    if (s.length % 2 !== 0) {
        return false;
    }
    return solveFrom(s, 0) == s.length;
}
function solveFrom(s, ptr) {
    if (ptr >= s.length) {
        return -1; // error.
    }
    const initial = s[ptr];
    if (initial === '(' || initial === '[' || initial === '{') {
        const final = solveFrom(s, ptr + 1);
        if (final === -1) {
            return -1;
        }
        if (closes(initial, s[final])) {
            if (final === s.length - 1) {
                return s.length;
            }
            return solveFrom(s, final + 1);
        }
    }
    return ptr;
}
function closes(a, b) {
    return (a === '(' && b === ')')
        || (a === '[' && b === ']')
        || (a === '{' && b === '}');
}
// tests
console.log(isValid('()')); // true
console.log(isValid('()[]{}')); // true
console.log(isValid('(]')); // false
console.log(isValid('([)]')); // false
