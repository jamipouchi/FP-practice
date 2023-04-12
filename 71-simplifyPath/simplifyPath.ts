function simplifyPath(path: string): string {
    const stack: string[] = [];
    const pathArr = path.split('/');
    for (const dir of pathArr) {
        if (dir === '..') {
            stack.pop();
        } else if (dir !== '.' && dir !== '') {
            stack.push(dir);
        }
    }
    return '/' + stack.join('/');
};

// Test
console.log(simplifyPath('/home/'));
console.log(simplifyPath('/../'));
console.log(simplifyPath('/home//foo/'));
console.log(simplifyPath('/a/./b/../../c/'));