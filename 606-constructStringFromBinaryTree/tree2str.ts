class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}

function tree2str(root: TreeNode): string {
    let result = root.val.toString();

    if (root.left != null) {
        result += "(" + tree2str(root.left) + ")";
    }
    else {
        if (root.right != null) {
            result += "()";
        }
    }
    if (root.right != null) {
        result += "(" + tree2str(root.right) + ")";
    }
    return result;
};

function treeFrom(arr: any[]): TreeNode {
    let root = new TreeNode(arr[0]);
    let queue = [root];
    let i = 1;
    while (queue.length > 0 && i < arr.length) {
        let node = queue.shift()! as TreeNode;
        if (arr[i] != null) {
            node.left = new TreeNode(arr[i]);
            queue.push(node.left);
        }
        i++;
        if (i < arr.length && arr[i] != null) {
            node.right = new TreeNode(arr[i]);
            queue.push(node.right);
        }
        i++;
    }
    return root;
}

console.log(tree2str(treeFrom([1, 2, 3, 4])))
console.log(tree2str(treeFrom([1, 2, 3, null, 4])))