/*
f(i, coins) = f(i - 1, coins - currentCoints) + currentSum
between 0 and min(piles[i - 1].length, coins)

*/

function maxValueOfCoins(piles: number[][], k: number): number {
    // Initialize the memoization array
    const n = piles.length;
    const C = Array(n).fill(0).map(() => Array(k + 1).fill(0));

    // We inittialize C[col][coins] with the cumSum of the piles.
    for (let col = 0; col < piles.length; col++) {
        C[col][0] = 0;
        let coins;
        for (coins = 1; coins <= Math.min(piles[col].length, k); coins++) {
            C[col][coins] = piles[col][coins - 1] + C[col][coins - 1];
        }
        while (coins <= k) {
            C[col][coins] = C[col][coins - 1];
            coins++;
        }
    }

    // Now we fill the memoization array.
    for (let col = 1; col < piles.length; col++) {

        for (let coins = k; coins >= 1; coins--) {
            for (let coinsFromCurrCol = 0; coinsFromCurrCol < coins; coinsFromCurrCol++) {
                C[col][coins] = Math.max(C[col][coins], C[col - 1][coins - coinsFromCurrCol] + C[col][coinsFromCurrCol]);
            }
        }
    }
    return C[n - 1][k];
};

// tests

console.log(maxValueOfCoins(
    [
        [1, 100, 3],
        [7, 8, 9],
    ], 2)); // 101

console.log(maxValueOfCoins(
    [
        [100],
        [100],
        [100],
        [1, 1, 1, 1, 1, 1, 700]
    ], 7)); // 706

// Is it really from i = 0, to n, best(getting i from col - 1 + k - i from col?))

console.log(maxValueOfCoins(
    [[37, 88], [51, 64, 65, 20, 95, 30, 26], [9, 62, 20], [44]], 9)); // 494