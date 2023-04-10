"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Node = void 0;
class Node {
    constructor(val, neighbors) {
        this.val = (val === undefined ? 0 : val);
        this.neighbors = (neighbors === undefined ? [] : neighbors);
    }
}
exports.Node = Node;
