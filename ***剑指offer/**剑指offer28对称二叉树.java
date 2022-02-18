/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/**
    主要问题在于想明白对称的判定的上
    对于向两边递归的节点来说 若为对称 
    应有 LRoot.R = RRoot.L  LRoot.L = RRoot.R
 */

class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root==null)
            return true;
        return recur(root.left,root.right);
    }

    private boolean recur(TreeNode L,TreeNode R){
        //到底了都为空 则必然对称
        if(L==null && R==null)
            return true;
        
        //一个空 一个非空必然不对称
        if(L==null || R==null)
            return false;
        
        if(L.val != R.val)
            return false;
        
        return recur(L.left,R.right)&&recur(L.right,R.left);
    }
}