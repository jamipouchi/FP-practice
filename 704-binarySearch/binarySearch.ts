function search(nums: number[], target: number): number {
    return binSearch(nums, target, 0, nums.length);
};

const binSearch = (nums: number[], target: number, l: number, r: number): number => {
    if (r <= l) {
        return -1;
    }
    const m = Math.floor((l + r) / 2);
    if (nums[m] == target) {
        return m;
    }
    return (nums[m] > target) ? binSearch(nums, target, l, m) : binSearch(nums, target, m + 1, r);

}

console.assert(search([-1, 0, 3, 5, 9, 12], 9) == 4);
console.assert(search([-1, 0, 3, 5, 9, 12], 2) == -1);

// Adding iterative for completeness


/* 
function search(nums: number[], target: number): number {

    let l: number  = 0;
let r: number = nums.length

while (l < r) {
    const m = Math.floor((l + r) / 2);
    if (nums[m] == target) {
        return m;
    }
    if (nums[m] > target) {
        r = m;
    }
    else {
        l = m + 1;
    }
}
return -1;
}; 
*/