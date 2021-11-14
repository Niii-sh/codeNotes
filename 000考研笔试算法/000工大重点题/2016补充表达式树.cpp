/*
    原题ACwing 3765
    工大16年那题比这个要简单一些用后序遍历就可以解决但这题也很可能
    会考吧 一开始还把思路想错了...
    一个必备的前提的知识中缀表达式 就是 表达式树的中缀遍历
    
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     string val；
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */
class Solution {
public:
    string dfs(TreeNode *root){
        if(!root)
            return "";
        if(!root->left&&!root->right)
            return root->val;
        string res="";
        res+="(";
        res+=dfs(root->left);
        res+=root->val;
        res+=dfs(root->right);
        res+=")";
        
        return res;
    }
    
    string expressionTree(TreeNode* root) {
        //主要是为了防止生成最外层的括号 不然最外层会多夹了一个括号
        return dfs(root->left)+root->val+dfs(root->right);
    }
};
