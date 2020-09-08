/*
解法1 记忆化搜索 (自底而上的DP)
定义 dp[][] 记录方案数
第一维表示未进栈的数 第二维表示在栈中的数
即i-1 j+1代表进栈 j-1 代表出栈
dp[][] 可由 dp[i+1][j-1] dp[i][j-1] 转换而来
当 j==0 时 不可出栈
i==n && j==0 搜索完毕
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20;

int dp[N][N];
int n;

int dfs(int i,int j){
    if(dp[i][j])    //有值则代表自底向上 已达到该层
        return dp[i][j];
    if(i==0)    //栈中已无元素(全部元素已经出栈) 搜索完毕
        return 1;
    if(j>0)     //j>0 栈中仍有元素 可以进行出栈操作
        dp[i][j] += dfs(i,j-1);
    //进栈
    dp[i][j] += dfs(i-1,j+1);

    return dp[i][j];    //记忆化搜索 返回已经存储的值
}

int main(){
    cin>>n;
    cout<<dfs(n,0)<<endl;;
    return 0;
}