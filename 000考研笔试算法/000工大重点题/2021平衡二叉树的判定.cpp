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
    主要思路:
    验明平衡二叉树的性质即可
    即 左右子树高度之差的绝对值 不超过为0或1 即等于1 且这个定义是递归的
    为此则需要一个专门计算高度的函数depth

    王道书上有不同的办法 但比较繁琐且不容易懂 显然是LC上这种递归的判定方法更符合树的性质 且简洁优雅
*/

class Solution {
public:
    int depth(TreeNode*root){
        if(!root)
            return 0;
        return max(depth(root->left),depth(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        //左右子树高度差不超过1 且该定义是递归的
        return abs(depth(root->left)-depth(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }
};