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
fn min_diff_in_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    fn inorder(
        node: &Option<Rc<RefCell<TreeNode>>>,
        prev_val: &mut Option<i32>,
        min_diff: &mut i32,
    ) {
        if let Some(node) = node {
            let TreeNode { left, right, val } = &*node.borrow();
            inorder(left, prev_val, min_diff);
            if let Some(diff) = prev_val.map(|prev_val| val - prev_val) {
                *min_diff = (*min_diff).min(diff);
            }
            *prev_val = Some(*val);
            inorder(right, prev_val, min_diff);
        }
    }
    let mut min_diff = i32::MAX;
    let mut prev_val = None;
    inorder(&root, &mut prev_val, &mut min_diff);
    min_diff
}
