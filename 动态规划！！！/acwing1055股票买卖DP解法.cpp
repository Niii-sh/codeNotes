/*
状态定义的DP 
与打家劫舍那题很像 定义状态接下来就比较简单了
另外要考虑初始化的问题
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1e5+10;

int dp[2][N];   //0表示持有当前的股票的最大收益 1表示当前手头无股票的最大收益
                //dp[0][i] = max(dp[0][i-1],dp[1][i-1]+a[i]);
                //dp[1][i] = max(dp[0][i-1]-a[i],dp[1][i-1]);
int n;
int a[N];

int main(){
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    for(int i=0;i<=n;i++)
        dp[1][i] = -1e9;
    
    for(int i=1;i<=n;i++){
        dp[0][i] = max(dp[0][i-1],dp[1][i-1]+a[i]);
        dp[1][i] = max(dp[0][i-1]-a[i],dp[1][i-1]);
    }
    
    printf("%d\n",max(dp[1][n],dp[0][n]));
    
    return 0;
}