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
    原题:LC 938
    二叉搜索树  左<根<右
    
    基本思路:dfs
    1.root节点为空
        返回0
    2.root节点的值大于high
        由于bst右子树上所有结点的值均大于根节点的值 
        即均大于high 故无需考虑右子树 返回左子树范围和
    3.root节点的值小于low
        由于bst左子树所有节点的值均小于根节点值
        即小于low 故无需考虑左子树 返回右子树范围和
    4.root节点的值在low high范围内
        此时应返回root节点的值左子树范围和 右子树范围和这三者之和

*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        if(root->val>high)
            return rangeSumBST(root->left,low,high);
        else if(root->val<low)
            return rangeSumBST(root->right,low,high);
        else
            return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};



