function findDifference(nums1: number[], nums2: number[]): number[][] {
    const set1 = new Set(nums1);
    const set2 = new Set(nums2);

    const ans: number[][] = [[],[]];

    for (const num of set1) {
        if (set2.has(num)) {
            set1.delete(num);
            set2.delete(num);
        }
        else {
            set1.delete(num);
            ans[0].push(num);
        }
    }
    for (const num of set2) {
        ans[1].push(num);
    }

    return ans;
};

// tests

console.log(findDifference([1, 2, 3], [2, 4, 6])) // [[1,3], [4,6]]
console.log(findDifference([1, 2, 2, 3], [1, 1, 2, 2])) // [[3], []]