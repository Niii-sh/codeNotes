/*
    原题LC 150
    栈的应用:
        逆波兰式 就是 后缀表达式
    就是使用最基本的栈的思路来求解
    如果遇到操作数，则将操作数入栈；
    如果遇到运算符，则将两个操作数出栈
    其中先出栈的是右操作数，后出栈的是左操作数，使用运算符对两个操作数进行运算，将运算得到的新操作数入栈。
    
    atoi()将字符串转换为一个整数
*/
class Solution {
public:
    bool isNumber(string &token){
        if(token!="+"&&token!="-"&&token!="*"&&token!="/")
            return true;
        return false; 
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;
        for(auto &token:tokens){
            if(isNumber(token)){
                stk.push(atoi(token.c_str()));
            }
            else{
                int num1,num2; //num1 为右操作数 先出栈 num2为左操作数 
                                //做除法时应该num2/num1 做减法应该 num2-num1
                num1 = stk.top();
                stk.pop();
                num2 = stk.top();
                stk.pop();
                char op = token[0];
                switch(op){
                    case '+':
                        stk.push(num1+num2);
                        break;
                    case '-':
                        stk.push(num2-num1);
                        break;
                    case '*':
                        stk.push(num1*num2);
                        break;
                    case '/':
                        stk.push(num2/num1);
                        break;
                }
            }
            
            }
            return stk.top();
        } 
    
};