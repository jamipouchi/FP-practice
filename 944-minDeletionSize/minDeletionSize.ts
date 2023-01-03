const minDeletionSize = (words: string[]): number => transpose(words.map(mySplit)).filter(not(sorted)).length;

const transpose = <T>(array: T[][]) => array[0].map((_, colIndex: number): T[] => array.map((row: T[]): T => row[colIndex]));
const mySplit = (word: string): string[] => word.split("");
const not = (f: (_: any) => boolean): (_: any) => boolean => (...args: any) => !f.apply(null, args); // don't really like you need to do this...
const sorted = (charWord: string[]): boolean => charWord.slice(1).every((c: string, i: number) => charWord[i] <= c);

console.log(minDeletionSize(["cba", "daf", "ghi"]));
console.log(minDeletionSize(["a", "b"]));
console.log(minDeletionSize(["zyx", "wvu", "tsr"]));
