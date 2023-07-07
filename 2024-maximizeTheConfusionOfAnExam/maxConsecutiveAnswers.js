"use strict";
function maxConsecutiveAnswers(answerKey, k) {
    let maxConsecutive = 0;
    const map = new Map();
    for (let right = 0; right < answerKey.length; right++) {
        map.set(answerKey[right], (map.get(answerKey[right]) || 0) + 1);
        let minor = Math.min(map.get('T') || 0, map.get('F') || 0);
        if (minor <= k) {
            maxConsecutive++;
        }
        else {
            map.set(answerKey[right - maxConsecutive], (map.get(answerKey[right - maxConsecutive]) || 0) - 1);
        }
    }
    return maxConsecutive;
}
;
console.log(maxConsecutiveAnswers("TTFF", 2));
console.log(maxConsecutiveAnswers("TFFT", 1));
console.log(maxConsecutiveAnswers("TTFTTFTT", 1));
