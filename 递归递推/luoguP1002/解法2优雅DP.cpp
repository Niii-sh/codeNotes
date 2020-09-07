//真心觉得这个 代码算是很优雅了 另外DP还是重要的 
//注意:以后干脆都用long long 好了 防止不必要的错误
/*
    DP的思路：
    由于只能向右或向下 
    所以易得 dp[i][j]必由 dp[i-1][j],dp[i][j-1]转移而来
    由于要求的是方案数 所以得：
    if(check1())不出界
    if(check2()==true) //不会被马吃掉 
        dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])+1;
    else
        dp[i][j] = max(dp[i-1][j]+dp[i][j-1])
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long LL;

const int N=30;

LL dp[N][N];
int g[N][N];
int n,m,hx,hy;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int dirhx[] = {-1,1,2,-2};
int dirhy[] = {-2,2,1,-1};

int main(){
    cin>>n>>m>>hx>>hy;

    g[hx][hy] = 1;
    
    //标记马可以走的位置
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            if(i<2&&j<2  || i>=2&&j>=2){
                int tx = hx + dirhx[i];
                int ty = hy + dirhy[j];

                if(tx<0 || tx>n || ty<0 || ty>n)
                    continue;
                
                g[tx][ty] = 1;
            }
        }

    dp[0][0]=1;

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++){
            if(g[i][j])
                continue;
            if(i==0 && j>0)
                dp[i][j] = dp[i][j-1];
            else if(i>0 && j==0)
                dp[i][j] = dp[i-1][j];
            else if(i>0 && j>0)
                dp[i][j] = max( dp[i][j] , dp[i-1][j] + dp[i][j-1] );
        }     
        

    cout<< dp[n][m] << endl;

    return 0;
}

