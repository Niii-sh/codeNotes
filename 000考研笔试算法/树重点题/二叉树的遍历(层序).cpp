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
    原题LC.102 
    二叉树的层序遍历
    基本思路:其实就是BFS 用一个队列即可
    (队列 队头出队 队尾入队)
    应用
    1.可以将链式存储的二叉树 展开为 相应的顺序存储 
    2.可以判断链式存储树是否是完全二叉树
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res ;
        if(!root)
            return res;
        queue<TreeNode*>q;
        q.push(root);

        int cursize = 1;

        while(!q.empty()){
            vector<int>tmp; 
            int newsize = 0;
            while(cursize>0){
                TreeNode* node = q.front();
                tmp.push_back(node->val);
                q.pop();
                if(node->left)
                    q.push(node->left),newsize++;
                if(node->right)
                    q.push(node->right),newsize++;
                cursize--;
            }          
            
            res.push_back(tmp);
            cursize = newsize;
        }      

        return res;
    }
};