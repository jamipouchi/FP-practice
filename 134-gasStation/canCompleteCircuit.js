var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
var canCompleteCircuit = function (gas, cost) {
    return gas.reduce(function (sum, curr) { return sum + curr; }) >= cost.reduce(function (sum, curr) { return sum + curr; })
        ? gas.length - gas
            .map(function (gasValue, idx) { return gasValue - cost[idx]; })
            .reduce(function (values, currValue) {
                var lastValue = values[values.length - 1];
                return lastValue < 0
                    ? __spreadArray(__spreadArray([], values, true), [0], false) : __spreadArray(__spreadArray([], values, true), [lastValue + currValue], false);
            }, [0])
            .findLastIndex(function (val) { return val < 0; })
        : -1;
};
console.log(canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]), " should be 3");
console.log(canCompleteCircuit([2, 3, 4], [3, 4, 3]), "should be -1");
console.log(canCompleteCircuit([5, 1, 2, 3, 4], [4, 4, 1, 5, 1]), "should be 4");
