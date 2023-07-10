"use strict";
function minDepth(root) {
    if (root === null) {
        return 0;
    }
    const Q = [root];
    let depth = 1;
    while (Q.length !== 0) {
        const layerSize = Q.length;
        for (let i = 0; i < layerSize; i++) {
            const node = Q.shift();
            if (node.left === null && node.right === null) {
                return depth;
            }
            if (node.left !== null) {
                Q.push(node.left);
            }
            if (node.right !== null) {
                Q.push(node.right);
            }
        }
        depth++;
    }
    return -1; // unreachable
}
;
