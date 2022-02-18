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
    原题LC94
    工大2017 
    中序遍历的非递归实现
    基本思路:
    先一路向左入栈 然后依次出栈 再将结点的右子树均入栈
    (每已进入根的右边可以理解为一次迭代过程)
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>stk;

        while(root!=nullptr||!stk.empty()){
            while(root!=nullptr){
                stk.push(root);
                root=root->left;
            }
            /*
                此处的转换 很灵活 到这里root已经为空故直接赋予新的值
                同时可顺利完成向右的过程代码简洁
            */
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);   
            root=root->right;
        }

        return ans;
    }
};