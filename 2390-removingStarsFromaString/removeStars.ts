function removeStars(s: string): string {
    const stack: string[] = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "*") {
            if (stack.length > 0) {
                stack.pop();
            }
        } else {
            stack.push(s[i]);
        }
    }
    return stack.join("");
};

// tests

function test1() {
    const s = "leet**cod*e";
    const expected = "lecoe";
    const actual = removeStars(s);
    console.log("test1", expected === actual);
}

function test2() {
    const s = "erase*****";
    const expected = "";
    const actual = removeStars(s);
    console.log("test2", expected === actual);
}

test1();
test2();