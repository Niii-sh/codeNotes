/*
    原题LC. 剑指 Offer II 036
    栈的应用--后缀表达式的求值
    
    手算方法(与本题代码无关但更重要 容易出现在应用题):
    从左往右扫描,每遇到一个运算符,
    就让前面最近的两个操作数执行对应的运算,合体为一个操作数
    !!最后出现的操作数先运算

    机算(代码思路):
    1.从左往右扫描下一个元素 直到处理完所有元素
    2.若扫描到操作数则压入栈 并回到1 否则执行3
    3.若扫描到运算符,则弹出两个栈顶元素,执行相应运算,运算结果压回栈顶回到1
    !!由于最后出现的操作数先运算 根据栈后进先出的原则 按照从左向右的顺序先出栈的应该是之后入栈的
    这个稍微有些乱反则就记得以除法为例 那么先出栈应该是除数 而出栈的应该是被除数
    即出栈顺序a b 那么运算结果是 b/a
*/

class Solution {
public:
    /*
        判断扫描到的是否为运算符号(+ - * -)
        是则执行3 即弹出两个栈顶元素 执行相应运算 运算结果压回栈顶
    */
    bool isOper(string op){
        if(op=="+"||op=="-"||op=="*"||op=="/")
            return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            string t = tokens[i];
            //如果不是运算符 那一定是操作数那么就入栈
            if(!isOper(t))
                st.push(stoi(t));
            //是运算符那么则弹出栈顶的两个元素进行计算 并将结果压回栈顶
            else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans;
                if(t=="+")
                    ans = a+b;
                if(t=="-")
                    ans = a-b;
                if(t=="*")
                    ans = a*b;
                if(t=="/")
                    ans = a/b;
                st.push(ans);
            }
        }   
        return st.top();
    }
};











