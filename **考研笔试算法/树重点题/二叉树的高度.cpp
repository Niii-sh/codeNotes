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
    原题LC 104
    用专业课的角度来讲就是 求树的高度
    比较重要可以说后续关于树的很多题的基础 被就完事了
    基本思路1:
    DFS 递归的思想
        如果我们知道了左子树和右子树的最大深度 l和r
        那么该二叉树的最大深度为
            max(l,r)+1
        而左子树和右子树的最大深度又可以同样的方式进行计算
        因此可以用DFS的方法
        先计算出左子树和右子树的深度 然后在O(1)的时间计算出当前二叉树的最大深度

    基本思路2 BFS:
        用队列实现类似于层序遍历
*/

class Solution {
public:
    int depth(TreeNode* root){
        if(!root)
            return 0;
        return max(depth(root->left),depth(root->right))+1;
    }

    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};