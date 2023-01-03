var minDeletionSize = function (words) { return transpose(words.map(mySplit)).filter(not(sorted)).length; };
var transpose = function (array) { return array[0].map(function (_, colIndex) { return array.map(function (row) { return row[colIndex]; }); }); };
var mySplit = function (word) { return word.split(""); };
var not = function (f) { return function () {
    var args = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        args[_i] = arguments[_i];
    }
    return !f.apply(null, args);
}; }; // don't really like you need to do this...
var sorted = function (charWord) { return charWord.slice(1).every(function (c, i) { return charWord[i] <= c; }); };
console.log(minDeletionSize(["cba", "daf", "ghi"]));
console.log(minDeletionSize(["a", "b"]));
console.log(minDeletionSize(["zyx", "wvu", "tsr"]));
