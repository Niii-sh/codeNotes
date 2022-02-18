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
    原题LC 617
    基本思路:
    dfs: 从根结点开始判断 相同则合并 否则就
    可以修改原树 也可以不修改
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;

        auto merged = new TreeNode(root1->val+root2->val);
        merged->left = mergeTrees(root1->left,root2->left);
        merged->right = mergeTrees(root1->right,root2->right);
        return merged;
    }
};  