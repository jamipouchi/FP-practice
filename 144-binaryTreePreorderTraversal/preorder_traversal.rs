// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}
impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::rc::Rc;
pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    if let Some(node_box) = root {
        let node_reference = node_box.borrow();

        vec![node_reference.val]
            .into_iter()
            .chain(preorder_traversal(node_reference.left.clone()).into_iter())
            .chain(preorder_traversal(node_reference.right.clone()).into_iter())
            .collect()
    } else {
        vec![]
    }
}
