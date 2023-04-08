function numRescueBoats(people: number[], limit: number): number {
    people.sort((a, b) => a - b);
    let numBoats: number = 0;
    let bigPtr: number = people.length - 1;
    let smallPtr: number = 0;
    while (smallPtr <= bigPtr) {
        if (people[bigPtr] + people[smallPtr] <= limit) {
            smallPtr++;
        }
        bigPtr--;
        numBoats++;
    }
    return numBoats;
};

// Tests
console.log(numRescueBoats([1, 2], 3)); // 1
console.log(numRescueBoats([3, 2, 2, 1], 3)); // 3
console.log(numRescueBoats([3, 5, 3, 4], 5)); // 4
