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
    递归判断
    遍历A的每个节点 
    边遍历A 边以当前所遍历的节点为根 与 B进行匹配判断 即判断子树recur
 */

class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {

        //按照空树不是 子树
        if(B==null)
            return false;
        
        if(A==null)
            return false;


        return recur(A,B) || isSubStructure(A.left,B) || isSubStructure(A.right,B);

    }

    //用于判断子树
    private boolean recur(TreeNode A,TreeNode B){
        //在B非空树前提 B的节点是空那肯定是 子树
        if(B==null)
            return true;
        
        /**
            在B非空的前提下
                如果A为空显然不是子树 算是一种剪枝
            如果值不匹配那更显然不是了    
         */
        if(A==null || A.val!=B.val)
            return false;

        return recur(A.left,B.left) && recur(A.right,B.right);
    }   

}