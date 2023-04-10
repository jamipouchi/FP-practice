"use strict";
const compareArrays = (a, b) => a.length === b.length && a.every((element, index) => element === b[index]);
const wordPattern = (pattern, w) => {
    if (pattern == "" && w == "") {
        return true;
    }
    else if (pattern == "" || w == "") {
        return false;
    }
    const p = pattern.charAt(0);
    const sWords = w.split(" ");
    //console.log(sWords, pattern);
    const s = sWords[0];
    //console.log(p, s);
    return compareArrays((pattern.split("").map(c => c === p)), (sWords.map(w => w === s))) &&
        wordPattern((pattern.replaceAll(p, "")), (sWords.filter(w => w !== s)).join(" "));
};
console.log(wordPattern("abba", "dog cat cat dog"));
console.log(wordPattern("abba", "dog cat cat fish"));
console.log(wordPattern("aaaa", "dog cat cat dog"));
