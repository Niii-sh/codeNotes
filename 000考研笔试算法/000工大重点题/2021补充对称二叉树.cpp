/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    原题LC 剑指offer 28
    基本思路和求二叉树的高度差不多
    都是一直递归下去 
    但注意的这个对称在每个子树内部中也是完全可以成立的
    所以 采取两边同时进行判断的方法
*/

class Solution {
public:
    bool recur(TreeNode*L,TreeNode*R){
        if(L==NULL&&R==NULL)
            return true;
        if(!L&&R || L&&!R || L->val!=R->val )
            return false;
        return recur(L->left,R->right)&&recur(L->right,R->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return recur(root->left,root->right);
    }
};