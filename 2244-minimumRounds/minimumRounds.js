"use strict";
const minimumRounds_fp_eff = (nums) => pack(nums.sort()).reduce(countAndSumIfPossible, 0);
const minimumRounds_fp_clean = (nums) => pack(nums.sort()).map(count).reduce(sumIfPossible);
// here T is constrained to be comparable (===), yet I don't know how to enforce that.
const pack = (elem) => rmHelper(elem.reduce((prev, curr) => {
    const lastIndex = prev.length - 1;
    if (prev[lastIndex][prev[lastIndex].length - 1] === curr) {
        const tilLast = prev.slice(0, lastIndex);
        const last = (prev.slice(lastIndex))[0];
        return [...tilLast, [...last, curr]];
    }
    else {
        return [...prev, [curr]];
    }
}, [[elem[0]]]));
const rmHelper = ([first, ...rest]) => [first.slice(1), ...rest];
const count = (elems) => {
    const mida = elems.length;
    if (mida < 2)
        return -1;
    else
        return Math.floor((mida + 2) / 3);
};
const sumIfPossible = (a, b) => {
    if (a === -1 || b === -1)
        return -1;
    else
        return a + b;
};
// sadly it gives tl :O
// I can unite map & reduce :(
const countAndSumIfPossible = (prev, rightElems) => {
    const mida = rightElems.length;
    if (mida < 2)
        return -1;
    else
        return sumIfPossible(prev, Math.floor((mida + 2) / 3));
};
// also tl.
// It is also possible to unite pack and reduce, but it's too fkn ugly. I am not doing that
// Might have been a good idea to choose a compiled language to try fp :)
// For those curious of a correct implementation (imperative)
// Note that I am not a ts/js expert. I am good at c++, and I'm coding what I'd do there.
const minimumRounds_Imp = (tasks) => {
    const numTasks = orderTasks(tasks);
    let minimumRounds = 0;
    for (const [_, val] of numTasks) {
        if (val < 2)
            return -1; // ending before
        else
            minimumRounds += Math.floor((val + 2) / 3);
    }
    return minimumRounds;
};
const orderTasks = (tasks) => {
    let numTasks = new Map();
    tasks.forEach((task) => {
        // I dislike how typescript makes me put that bang.
        const taskNum = numTasks.has(task) ? numTasks.get(task) : 0;
        numTasks.set(task, taskNum + 1);
    });
    return numTasks;
};
