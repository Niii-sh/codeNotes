/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/*
    独立写出来的一题 有点找到感觉了
    把复杂的题目简单化 从熟悉的先开始考虑
*/

class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null)
            return root;

        return mirror(root);
    }

    private TreeNode mirror(TreeNode root){
        if(root==null)
            return root;
        
        TreeNode mirrorRoot = new TreeNode(root.val);

        mirrorRoot.right =  mirror(root.left);
        mirrorRoot.left = mirror(root.right);

        return mirrorRoot;
    }
}