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
    前序遍历找根 在中序中进行划分
*/

class Solution {
private:
    //建立节点值与其在中序数组中位置的映射
    //<节点值,在中序数组中的位置>
    unordered_map<int,int>mapInorder;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        
        for(int i=0;i<n;i++)
            mapInorder[inorder[i]] = i;

        return rebuild(preorder,inorder,0,n-1,0,n-1);
    }
    /*
        参数说明:
        原前序数组 原中序数组 前序数组左边界 右边界  中序数组左边界 右边界
    */
    TreeNode* rebuild(vector<int>&preorder,vector<int>&inorder,int pre_l,int pre_r,int in_l,int in_r){
        if(pre_l>pre_r)
            return nullptr; 

        TreeNode*root = new TreeNode(preorder[pre_l]);

        int inorderRootIndex = mapInorder[root->val];   //节点在中序数组中的位置

        int sub_left_size = inorderRootIndex - in_l;

        root->left = rebuild(preorder,inorder,pre_l+1,pre_l+sub_left_size,in_l,inorderRootIndex-1);
        root->right = rebuild(preorder,inorder,pre_l+sub_left_size+1,pre_r,inorderRootIndex+1,in_r);

        return root;
    }

};
