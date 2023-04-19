function mergeAlternately(word1: string, word2: string): string {
    let result = [];
    let i = 0;
    let j = 0;
    while (i < word1.length && j < word2.length) {
        result.push(word1[i]);
        i++;
        result.push(word2[j]);
        j++;
    }
    while (i < word1.length) {
        result.push(word1[i]);
        i++;
    }
    while (j < word2.length) {
        result.push(word2[j]);
        j++;
    }
    return result.join("");
};

// Some test cases
console.log(mergeAlternately("abc", "pqr")); // "apbqcr"
console.log(mergeAlternately("ab", "pqrs")); // "apbqrs"
console.log(mergeAlternately("abcd", "pq")); // "apbqcd"