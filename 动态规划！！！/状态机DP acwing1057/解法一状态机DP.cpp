#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e5+10;
const int M = 110;

int w[N];
int dp[N][M][2];    //dp i,j,0 表示第i天 进行完前j次交易 手上无货的状态
                    //dp i,j,1 表示第i天 正在进行第j此交易 手上有货的状态
/*
关于状态的初始化:
dp i 0 0 即没有进行任何一次交易时手上无货 则此时的总价值一定为0
dp i 0 1 即正在进行第0次交易时 那么不存在这种状态 将其初始化为负无穷
*/

int n,k;

int main(){
    scanf("%d%d",&n,&k);
    
    
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
        
    memset(dp,-0x3f,sizeof dp);
    
    for(int i=0;i<=n;i++)
        dp[i][0][0] = 0;
    
    
    /*
        在进行状态转移的时候 需注意对于状态的定义
        j=0 即手上无货的情况 是可以 从j=0 和 j=1转换而来
        而手上有货需要卖掉手上的货才能变为手中无货的价值对应的转变即为+w[i]
        同理从手上无货到手上有货也是一个道理 需要-w[i]
    */
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++){
            dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1]+w[i]);
            dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0]-w[i]);
        }
    
    int res=0;
    
    for(int i=0;i<=k;i++){
        res = max(res,dp[n][i][0]);
        res = max(res,dp[n][i][1]);
    }
        
    printf("%d\n",res);
    
    return 0;
}