var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
var minimumRounds = function (nums) { return pack(nums.sort()).reduce(countAndSumIfPossible, 0); };
//.map(count).reduce(sumIfPossible)
// here T is constrained to be comparable (===), yet I don't know how to enforce that.
var pack = function (elem) { return rmHelper(elem.reduce(function (prev, curr) {
    var lastIndex = prev.length - 1;
    if (prev[lastIndex][prev[lastIndex].length - 1] === curr) {
        var tilLast = prev.slice(0, lastIndex);
        var last = (prev.slice(lastIndex))[0];
        return __spreadArray(__spreadArray([], tilLast, true), [__spreadArray(__spreadArray([], last, true), [curr], false)], false);
    }
    else {
        return __spreadArray(__spreadArray([], prev, true), [[curr]], false);
    }
}, [[elem[0]]])); };
var rmHelper = function (_a) {
    var first = _a[0], rest = _a.slice(1);
    return __spreadArray([first.slice(1)], rest, true);
};
var count = function (elems) {
    var mida = elems.length;
    if (mida < 2)
        return -1;
    else
        return Math.floor((mida + 2) / 3);
};
var sumIfPossible = function (a, b) {
    if (a === -1 || b === -1)
        return -1;
    else
        return a + b;
};
// sadly it gives tl :O
// I can unite map & reduce :(
var countAndSumIfPossible = function (prev, rightElems) {
    var mida = rightElems.length;
    if (mida < 2)
        return -1;
    else
        return sumIfPossible(prev, Math.floor((mida + 2) / 3));
};
// also tl.
// It is also possible to unite pack and reduce, but it's too fkn ugly. I am not doing that
