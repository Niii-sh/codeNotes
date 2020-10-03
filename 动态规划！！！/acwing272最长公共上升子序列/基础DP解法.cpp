/*
其实主要还是分两步
虽然是同时进行 但只有当状态转移符合最长公共子序列的情况下
才需要对 最长上升子序列的情况进行讨论
在此基础 将这个问题分解 便清晰明了了
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 3010;

int n;
int a[N],b[N];
int dp[N][N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)   
        cin>>a[i];
    
    for(int j=1;j<=n;j++)
        cin>>b[j];
        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            /*
                这步的状态转移比较重要
                不可完全照搬 最长公共上升子序列的解法
                由于状态划分是根据是否包含ai 划分的
                而我们无法确定 i j-1 是否是符合条件最长上升子序列
                故状态只能由 dp[i-1][j] 转移而来 而不能从dp[i][j-1]转移
            
            */
            dp[i][j] = dp[i-1][j];
            if(a[i]==b[j]){
                dp[i][j] = max(dp[i][j],1);
                for(int k=1;k<j;k++){
                    if(b[k]<b[j])
                        dp[i][j] = max(dp[i][j],dp[i][k] + 1);
                }
            }
        }
    }
    
    int res=0;
    
    for(int  i=1;i<=n;i++)
        res = max(res,dp[n][i]);
    
    cout<<res<<endl;
        
    return 0;
}

