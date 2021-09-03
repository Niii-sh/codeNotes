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
    原题:LC653
    基本思路:利用BST的性质
        BST中序遍历的结果为有序序列
        所以只需按照中序遍历的加入数组 然后再用双指针判断即可
*/

class Solution {
public:
    void inOrderTraverse(TreeNode *root,vector<int>&nums){
        if(root->left)
            inOrderTraverse(root->left,nums);
        if(root)
            nums.push_back(root->val);
        if(root->right)
            inOrderTraverse(root->right,nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>nums;
        inOrderTraverse(root,nums);
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]<k)
                l++;
            else if(nums[l]+nums[r]>k)
                r--;
            else 
                return true;          
        }
        return false;
    }
};