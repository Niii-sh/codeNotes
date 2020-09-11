/*
基本思路:递归
递归出口 u==0 当前已经算2(0)的情况 即最内层
定义p 寻找当前这个数2(p)恰好小于u的 p
判断p的值
1.p==0 输出2(0)  (这里带右括号是因为递归出口为n==0 不会递归进入下一层)
2.p==1 输出2
3.p>1  输出2(   
    然后再次进入递归 
    回溯(应该是叫回溯吧... 也不太确定 就是在内层递归以后的意思)后输出')'
    注:这个第3步 应该真正体现出一些递归精华的一步 也是递归逻辑巧妙之处的一步
        也是最值得学习的一步
4.判断u==pow(2,p) 只有u=1 p=0时 两者才有可能相等即只有这种情况下才无须打印"+"

总结很好的一道递归题 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;

int pow(int a,int b){
    int c=1;
    for(int i=0;i<b;i++)
        c*=a;
    return c;
}

void dfs(int u){
    int p=0;
    if(u==0)
        return;
    
    for(int i=0;i<=15;i++){
        if(pow(2,i)>u){
            p=i-1;  //存储恰好小于u的位置 
            break;
        }
    };

    if(p==0)
        printf("2(0)");
    if(p==1)
        printf("2");
    if(p>1){
        printf("2(");
        dfs(p);
        printf(")");
    }

    if(u!=pow(2,p)){
        printf("+");
        dfs(u-pow(2,p));
    }

}

int main(){
    cin>>n;
    dfs(n);
    return 0;
}