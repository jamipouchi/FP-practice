"use strict";
const minDeletionSize = (words) => transpose(words.map(mySplit)).filter(not(sorted)).length;
const transpose = (array) => array[0].map((_, colIndex) => array.map((row) => row[colIndex]));
const mySplit = (word) => word.split("");
const not = (f) => (...args) => !f.apply(null, args); // don't really like you need to do this...
const sorted = (charWord) => charWord.slice(1).every((c, i) => charWord[i] <= c);
console.log(minDeletionSize(["cba", "daf", "ghi"]));
console.log(minDeletionSize(["a", "b"]));
console.log(minDeletionSize(["zyx", "wvu", "tsr"]));
