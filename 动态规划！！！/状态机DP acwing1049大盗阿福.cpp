#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int  N = 1e5+10;

int a[N];
int n,T;
int dp[N][2];   //dp i,j 表示抢劫前i家店不被发现情况下所获得的最大收益
                //j=0表示不抢这家店 
                //dp[i][0] = max(dp[i-1][0],dp[i-1][1])
                //j=1表示抢了这家店
                //dp[i][1] = (dp[i-1][0]+a[i])

int main(){
    scanf("%d",&T);
    
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
            
        memset(dp,0,sizeof dp);
        
        for(int i=1;i<=n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + a[i];
        }
        
        printf("%d\n",max(dp[n][0],dp[n][1]));
    }
    
    return 0;
}

