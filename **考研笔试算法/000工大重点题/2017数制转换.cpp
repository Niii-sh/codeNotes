/*
    数制转换(工大2017年原题)
    主要思路:
    利用栈 将num转换为b进制的数字(b<=16) 
    1.将该数字从低位到高温每位对应的10进制值从字符串中取值存入栈中
    2.利用栈的先入后出实现从低位到高位的输出 即输出num的b进制转换结果
*/

#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

string convert(int num,int b){
    string digtChar = "0123456789ABCDEF";
    string ans="";
    stack<char>stk;
    
    do{
        stk.push(digtChar[num%b]);
        num/=b;
    }while(num!=0);
    
    while(!stk.empty()){
        ans+=stk.top();
        stk.pop();
    }
    
    return ans;
}


int main(){
    int num,b;
    cin>>num>>b;
    cout<<convert(num,b);
    
    return 0;
}