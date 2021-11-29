/*
    原题LC 剑指offer 31
    直接模拟的思路
    定义一个辅助栈 入栈序列先入辅助栈
    然后 依次出栈判断与出栈序列是否相同
    感觉这个点还是完全有可能拿来考的
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>stk;
        int i=0;
        for(int u:pushed){
           stk.push(u); 
           while(!stk.empty()&&stk.top()==popped[i]){
               stk.pop();
               i++;
           }
        }

        return stk.empty();
    }
};