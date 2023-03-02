var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
function compress(chars) {
    var aha = chars.reduce(function (_a, currChar) {
        var _b = _a[0], char = _b.char, count = _b.count, rest = _a.slice(1);
        if (currChar === char) {
            return __spreadArray([{ char: currChar, count: count + 1 }], rest, true);
        }
        else {
            return __spreadArray([{ char: currChar, count: 1 }, { char: char, count: count }], rest, true);
        }
    }, [{ char: '', count: 0 }]);
    console.log(aha);
    chars = aha.reverse().flatMap(function (_a) {
        var char = _a.char, count = _a.count;
        return [char, count.toString()];
    }).slice(2);
    console.log(chars);
    return chars.length;
}
var chars = ["a", "a", "b", "b", "c", "c", "c"];
console.log(compress(chars));
