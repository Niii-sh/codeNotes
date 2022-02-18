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
    原题LC530
    基本思路:
        中序遍历 处理BST相关序列值最好的办法就是中序遍历展开为有序的序列
        然后按照正常数组的办法去处理
*/

class Solution {
public:
    void inOrderTraverse(TreeNode*root,vector<int>&nums){
        if(root->left)
            inOrderTraverse(root->left,nums);
        if(root)
            nums.push_back(root->val);
        if(root->right)
            inOrderTraverse(root->right,nums);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int>nums;
        inOrderTraverse(root,nums);
        int ans=nums[1]-nums[0];

        for(int i=1;i<nums.size()-1;i++){
            ans=min(ans,nums[i+1]-nums[i]);
        }

        return ans;
    }
};