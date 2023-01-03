var compareArrays = function (a, b) { return a.length === b.length && a.every(function (element, index) { return element === b[index]; }); };
var wordPattern = function (pattern, w) {
    if (pattern == "" && w == "") {
        return true;
    }
    else if (pattern == "" || w == "") {
        return false;
    }
    var p = pattern.charAt(0);
    var sWords = w.split(" ");
    //console.log(sWords, pattern);
    var s = sWords[0];
    //console.log(p, s);
    return compareArrays((pattern.split("").map(function (c) { return c === p; })), (sWords.map(function (w) { return w === s; }))) &&
        wordPattern((pattern.replaceAll(p, "")), (sWords.filter(function (w) { return w !== s; })).join(" "));
};
console.log(wordPattern("abba", "dog cat cat dog"));
console.log(wordPattern("abba", "dog cat cat fish"));
console.log(wordPattern("aaaa", "dog cat cat dog"));
