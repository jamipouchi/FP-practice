class TreeNode(
    _value: Int = 0,
    _left: TreeNode = null,
    _right: TreeNode = null
) {
  var value: Int = _value
  var left: TreeNode = _left
  var right: TreeNode = _right
}

object Solution {
  def averageOfSubtree(root: TreeNode): Int = {
    total = 0
    averageOfSubtreeHelper(root)
    total
  }

  private def averageOfSubtreeHelper(root: TreeNode): (Int, Int) = {
    var (sum, count): (Int, Int) = (0, 0)
    root.left match {
      case null => { sum += root.value; count += 1 }
      case _ => {
        val (leftSum, leftCount) = averageOfSubtreeHelper(root.left)
        sum += leftSum
        count += leftCount
      }
    }
    root.right match {
      case null => { sum += root.value; count += 1 }
      case _ => {
        val (rightSum, rightCount) = averageOfSubtreeHelper(root.right)
        sum += rightSum
        count += rightCount
      }
    }
    if (root.value == (sum / count)) {
        total += 1
    }
    return (sum, count)
  }
  private var total: Int = 0
}
