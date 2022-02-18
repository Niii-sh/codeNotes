/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    原题LC 110
    基本思路:
        主要就是验明平衡二叉树的最重要的一条性质:
        平衡二叉树每个结点的左右两个子树高度差的绝对值不超过1
        具体做法:
            类似于二叉树的前序遍历,
            即当对于当前遍历到的结点 首先计算左右子树的高度
            判断左右子树的高度差是否不超过1 
            再分别递归地遍历左右子树子结点 并判断左子树和右子树是否平衡           
*/

class Solution {
public:
    int depth(TreeNode* root){
        if(!root)
            return 0;
        return max(depth(root->left),depth(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return abs(depth(root->left)-depth(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};