const maxIceCream = (costs: number[], coins: number): number =>
    costs
        .sort((a: number, b: number): number => a - b)
        .reduce((remaining: number, nextCost, idx: number, arr: number[]) => {
            console.log(remaining, nextCost)
            if (nextCost > remaining) {
                arr.splice(idx); // This is to eject from the reduce!
                return idx;
            }
            else if (idx + 1 === arr.length) {
                return arr.length;
            }
            else
                return remaining - nextCost;
        }, coins)

console.log(maxIceCream([1, 3, 2, 4, 1], 7), " should be 4");
console.log(maxIceCream([10, 6, 8, 7, 7, 8], 5), " should be 0");
console.log(maxIceCream([1, 6, 3, 1, 2, 5], 20), " should be 6");
console.log(maxIceCream([10, 2, 10, 10, 10, 10, 8, 2, 7, 8], 25), " should be 4");