/*
这题用状态机模型分析 画出状态图后事实上已经很明确了
但主要问题还是在边界赋值处理上
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e5+10;

//DP状态表示 
//dp i 0 表示第i天 手上有货 所得收益的最大值
//dp i 1 表示第i天 手上无货第一天(冻结期) 所得收益的最大值
//dp i 2 表示第i天 手上无货第>=2天 所得收益的最大值
int dp[N][3];   

int w[N];
int n;

int main(){
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    
    /*
        关于初始化
        dp 0 0 第0天 手上无货  dp 0 1 第0天 手上有货 这两种状态均无法到达 属于边界状态赋值为负无穷 
        dp 0 2 为入口状态 这是因为第一次购买的股票肯定不处于冷冻期 所以可以直接进行买卖 故赋值为0
    */
    
    dp[0][1] = dp[0][0] = -1e9 ;
    dp[0][2] = 0;
    
    for(int i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][2]-w[i]);
        dp[i][1] = dp[i-1][0] + w[i];
        dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
    }
    
    //理论上来说 dp[n][2]的状态应包含于dp[n][1]中
    //但存在边界情况 故取max(dp[n][1],dp[n][2]) 输出
    printf("%d\n",max(dp[n][1],dp[n][2]));
    
    return 0;
}
