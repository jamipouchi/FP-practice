const compareArrays = <T>(a: T[], b: T[]) => a.length === b.length && a.every((element: T, index: number) => element === b[index]);

const wordPattern = (pattern: string, w: string): boolean => {
    if (pattern == "" && w == "") {
        return true;
    }
    else if (pattern == "" || w == "") {
        return false;
    }

    const p: string = pattern.charAt(0);
    const sWords: string[] = w.split(" ");
    //console.log(sWords, pattern);
    const s: string = sWords[0];
    //console.log(p, s);

    return compareArrays(
        (pattern.split("").map(c => c === p)),
        (sWords.map(w => w === s))) &&
        wordPattern(
            (pattern.replaceAll(p, "")),
            (sWords.filter(w => w !== s)).join(" "));
};

console.log(wordPattern("abba", "dog cat cat dog"));
console.log(wordPattern("abba", "dog cat cat fish"));
console.log(wordPattern("aaaa", "dog cat cat dog"));
