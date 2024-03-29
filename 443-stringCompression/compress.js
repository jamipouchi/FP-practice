"use strict";
function compress(chars) {
    let aha = chars.reduce(([{ char, count }, ...rest], currChar) => {
        if (currChar === char) {
            return [{ char: currChar, count: count + 1 }, ...rest];
        }
        else {
            return [{ char: currChar, count: 1 }, { char, count }, ...rest];
        }
    }, [{ char: '', count: 0 }]);
    console.log(aha);
    chars = aha.reverse().flatMap(({ char, count }) => [char, count.toString()]).slice(2);
    console.log(chars);
    return chars.length;
}
let chars = ["a", "a", "b", "b", "c", "c", "c"];
console.log(compress(chars));
