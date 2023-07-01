"use strict";
/* class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
} */
var Direction;
(function (Direction) {
    Direction[Direction["Left"] = 0] = "Left";
    Direction[Direction["Right"] = 1] = "Right";
    Direction[Direction["Start"] = 2] = "Start";
})(Direction || (Direction = {}));
// This is genius. Actually implemented by copilot
function longestZigZag(root) {
    let max = 0;
    const dfs = (node, direction) => {
        if (!node)
            return 0;
        let left = dfs(node.left, Direction.Left);
        let right = dfs(node.right, Direction.Right);
        max = Math.max(max, left, right);
        return direction === Direction.Left ? right + 1 : left + 1;
    };
    dfs(root, Direction.Start);
    return max;
}
;
// test cases
function test() {
    let root = new TreeNode(1);
    root.left = new TreeNode(1);
    root.left.left = new TreeNode(1);
    root.left.right = new TreeNode(1);
    root.left.right.left = new TreeNode(1);
    root.left.right.right = new TreeNode(1);
    root.left.right.right.left = new TreeNode(1);
    root.left.right.right.right = new TreeNode(1);
    root.right = new TreeNode(1);
    root.right.left = new TreeNode(1);
    root.right.right = new TreeNode(1);
    root.right.right.right = new TreeNode(1);
    root.right.right.right.right = new TreeNode(1);
    root.right.right.right.right.right = new TreeNode(1);
    root.right.right.right.right.right.right = new TreeNode(1);
    root.right.right.right.right.right.right.right = new TreeNode(1);
    console.log(longestZigZag(root)); // 3
}
test();
