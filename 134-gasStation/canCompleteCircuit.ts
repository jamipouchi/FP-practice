const canCompleteCircuit = (gas: number[], cost: number[]): number => {
    if (gas.reduce((sum, curr) => sum + curr) >= cost.reduce((sum, curr) => sum + curr)) {
        const lastIdx = gas
            .map((gasValue, idx) => gasValue - cost[idx])
            .reduce((values: number[], currValue: number) => {
                const lastValue = values[values.length - 1];
                return lastValue < 0
                    ? [...values, currValue]
                    : [...values, lastValue + currValue]
            }, [0])
            .reverse()
            .findIndex((val) => val < 0)
        return lastIdx == -1 ? 0 : gas.length - lastIdx;
    }
    else {
        return -1;
    }
}

console.log(canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]), " should be 3");
console.log(canCompleteCircuit([2, 3, 4], [3, 4, 3]), "should be -1");
console.log(canCompleteCircuit([5, 1, 2, 3, 4], [4, 4, 1, 5, 1]), "should be 4");