"use strict";
function longestPalindromeSubseq(s) {
    const n = s.length;
    let dp = new Array(n).fill(0);
    let dpPrev = new Array(n).fill(0);
    for (let i = n - 1; i >= 0; i--) { // We start filling from bottom right
        dp[i] = 1;
        for (let j = i + 1; j < n; j++) {
            if (s[i] === s[j]) {
                dp[j] = dpPrev[j - 1] + 2;
            }
            else {
                dp[j] = Math.max(dpPrev[j], dp[j - 1]);
            }
        }
        dpPrev = [...dp];
    }
    return dp[n - 1];
}
;
/* x is base case l = 1, empty spaces contain 0
x7890
 x456
  x23
   x1
    x
*/
// test
console.log(longestPalindromeSubseq('bbbab')); // 4
console.log(longestPalindromeSubseq('cbbd')); // 2
