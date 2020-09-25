/*
基本思路DP：
    这个算是模板题了..
    稍微改了一下摘花生那题吧
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N=50;

int n,m;
int dp[N][N];

int main(){
    cin>>n>>m;

    
    //初始化
    //根据定义从(1,1)走到(1,i)和(i,1)的方案数 只有直着走过去一种
    //所以均初始化为1
    for(int i=1;i<=m;i++)   
        dp[1][i]=1;
    
    for(int i=1;i<=n;i++)
        dp[i][1]=1;
    
    //dp递推从2 开始
    //因为是从(1,1)出发的 所以i=1,j=1为边界情况
    for(int i=2;i<=n;i++)   
        for(int j=2;j<=m;j++)
            if(i%2 || j%2)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] ;

    cout<< dp[n][m];

    return 0;
}