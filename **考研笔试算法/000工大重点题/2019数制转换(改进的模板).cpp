/*
    数值转换转换：
    基本思路:
    r为权重
    a[i]= num%r num/=r 直到num=0
    然后如果是16进制的话则需将数字转换为相应的字符
    注意这样的存储在数组中的顺序是反的
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//完美版本也是最方便的版本  结合18年的题 改进的
//考试的时候如果是代码题就用这种
void convert(int num,int r){
    string digitChar="0123456789ABCDEF";
    stack<int>s;
    while(num){
        s.push(num%r);
        num/=r;
    }
    
    string ans="";
    
    while(s.empty()==false){
        ans+=digitChar[s.top()];
        s.pop();
    }
    
    cout<<ans<<endl;
}

//不完美版本程序阅读遇到 很不优雅但要会
//主要体现在 数转换为字符时需要手动转换 且需要逆序输出
void convertTo16(int num){
    int a[100],i=0;
    char ch;
    while(num){
        a[i++]=num%16;
        num/=16;
    }
    
    for(i--;i>=0;i--){
        if(a[i]>9)
            ch='A'+a[i]-10;
        else
            ch=a[i]+'0';
        cout<<ch;
    }
    
}


int main(){
    convert(135,16);
    return 0;
}