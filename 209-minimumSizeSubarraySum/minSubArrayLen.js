"use strict";
function minSubArrayLen(target, nums) {
    let left = 0;
    let right = 0;
    let value = 0;
    let minLen = nums.length + 1;
    while (right < nums.length) {
        while (right < nums.length && value < target) {
            value += nums[right];
            right++;
        }
        while (value >= target) {
            value -= nums[left];
            left++;
        }
        minLen = Math.min(minLen, right - left + 1);
    }
    return (minLen === nums.length + 1) ? 0 : minLen;
}
;
console.log(minSubArrayLen(7, [2, 3, 1, 2, 4, 3]));
console.log(minSubArrayLen(4, [1, 4, 4]));
console.log(minSubArrayLen(11, [1, 1, 1, 1, 1, 1, 1, 1]));
