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
    基本思路:
        每次选取中间节点作为根 
        如果是奇数节点的情况 则解唯一 是偶数则左右均可 但在写代码的时候要注意区分
        选取中间节点左边的点则 mid=(left+right)/2;
        选取中间节点右边的点则 mid=(left+right+1)/2;
        然后递归的建立即可

        下面代码展示的是选取中间节点左边的点作为根
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }

    TreeNode* helper(vector<int>&nums,int left,int right){
        if(left>right)
            return nullptr;
        int mid = (left+right)/2;   //每次选用中间节点左边的作为中间值
        TreeNode *root = new TreeNode(nums[mid]);
        root->left= helper(nums,left,mid-1);
        root->right= helper(nums,mid+1,right);
        return root;
    }
};