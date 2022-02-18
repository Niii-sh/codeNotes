/*
    原题LC.20 
    栈的应用
    基本思路: 
    依次扫描所有的字符,遇到左括号入栈,遇到右括号则弹出栈顶元素检查是否匹配
    匹配失败的情况：
    1.左括号单身---栈不空但已完成遍历
    2.右括号单身---栈空 但未完成遍历
    3.左右括号不匹配
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            //如果是左括号则入栈
            char ch = s[i];
            if(ch=='('||ch=='{'||ch=='[')
                st.push(ch);
            //如果是右括号的情况 
            //本题的情况比较特殊只有左右括号组成 所以直接放在else里面就可以了 
            //如果正常字符串需要对正常字符进行判断
            else{   
            　   //右括号单身的情况 栈空但未完成遍历
                if(st.empty())
                    return false;
                char t = st.top();
                st.pop();
                //是否匹配的情况
                if(t=='('&&ch!=')' || t=='{'&&ch!='}' || t=='['&&ch!=']' )
                    return false;
            }
        }
        
        //左括号单身的情况 栈不空但已完成遍历
        if(!st.empty())
            return false;

        return  true;
    }
};