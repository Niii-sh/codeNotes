/*
调试了无数次的题
最后还是在80分的时候放弃了....
选错了数据结构 对题意的理解也有一些问题
题目本身不怎么难 
这种题目最好还是要把思路理清楚吧 
先从基础的递归开始练吧  递归毕竟思路清晰一些 也好调试很多
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=20;

string s;
int p;
string dfs(){
    string str;
    string ans;
    while(p<s.size()){
        if(isalpha(s[p]))
            ans+=s[p];
        else if(s[p]=='['){
            p++;
            int t=0;
            while(isdigit(s[p])){
                t*=10;
                t+=s[p]-'0';
                p++;
            }

            str=dfs();
            for(int i=0;i<t;i++)
                ans+=str;
        }

        else if(s[p]==']')
            return ans;
        
        else ans+=str;

        p++;
    }

}

int main(){
    cin>>s;
    
    cout<<dfs()<<endl;
    return 0;
}