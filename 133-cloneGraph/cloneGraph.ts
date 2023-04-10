import { Node } from './node';


// We must take into account if we have already visited a node

function cloneGraph(node: Node | null): Node | null {
    if (node === null) {
        return null;
    }
    const currNode: Node = new Node(node.val);

    const visitedNodes = new Map<number, Node>();
    visitedNodes.set(currNode.val, currNode);

    cloneRecursive(node, visitedNodes);

    return currNode;
};

const cloneRecursive = (node: Node, visitedNodes: Map<number, Node>): void => {
    const currNode = visitedNodes.get(node.val)!; // ! is used to tell the compiler that we are sure that the value exists

    for (const neighbor of node.neighbors) {
        if (!visitedNodes.has(neighbor.val)) {
            const clonedNeighbor = new Node(neighbor.val);
            visitedNodes.set(clonedNeighbor.val, clonedNeighbor);
            currNode.neighbors.push(clonedNeighbor);
            cloneRecursive(neighbor, visitedNodes);
        } else {
            currNode.neighbors.push(visitedNodes.get(neighbor.val)!);
        }
    }
};

// tests

const node1 = new Node(1);
const node2 = new Node(2);
const node3 = new Node(3);
const node4 = new Node(4);

node1.neighbors = [node2, node4];
node2.neighbors = [node1, node3];
node3.neighbors = [node2, node4];
node4.neighbors = [node1, node3];

const clonedNode = cloneGraph(node1);

console.log(clonedNode);