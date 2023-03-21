function zeroFilledSubarray(nums: number[]): number {
    let numberOfSubarrays = 0;
    [...nums, 1].reduce((zeros, num) => {
        if (num === 0) {
            return zeros + 1
        }
        else {
            numberOfSubarrays += zeros*(zeros+1) / 2;
            return 0
        }
    }, 0);
    return numberOfSubarrays;
};