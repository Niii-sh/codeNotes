/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

/**
    思路蛮简单的
    但是java语法的坑真的比较多不像C++那么方便
 */
class Solution {
    private LinkedList<List<Integer>>  res  = new LinkedList ();
    private LinkedList<Integer> path = new LinkedList<>(); 

    public List<List<Integer>> pathSum(TreeNode root, int target) {
        dfs(root,target);
        return res;
    }

    private void dfs(TreeNode root , int tar){
        if(root == null)
            return;
        int val = root.val;
        tar-=val;
        path.add(val);

        // 结果为tarSum 且 为叶子节点
        if(tar == 0 && root.left == null && root.right == null)
            res.add(new LinkedList(path));

        dfs(root.left,tar);
        dfs(root.right,tar);
        tar+=val;
        path.removeLast();
    }
}