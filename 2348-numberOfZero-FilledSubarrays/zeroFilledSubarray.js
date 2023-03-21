var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
function zeroFilledSubarray(nums) {
    var numberOfSubarrays = 0;
    __spreadArray(__spreadArray([], nums, true), [1], false).reduce(function (zeros, num) {
        if (num === 0) {
            return zeros + 1;
        }
        else {
            numberOfSubarrays += zeros * (zeros + 1) / 2;
            return 0;
        }
    }, 0);
    return numberOfSubarrays;
}
;
