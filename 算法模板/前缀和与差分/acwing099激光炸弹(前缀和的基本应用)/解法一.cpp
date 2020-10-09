/*
养成较为良好的编程习惯
题设给的字母可能通常会有些乱..
用n,m 代表行列
r 代表爆炸范围边长
cnt 记录数据组数

另外前缀和由于需要用到n-1 所以最好数组是从1开始
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5010;

int s[N][N];

int n,m,r,cnt;

int main(){
    cin>>cnt>>r;
    
    r=min(r,5001);
    
    n=m=r;
    
    while(cnt--){
        int x,y,w;
        cin>>x>>y>>w;
        x++;
        y++;
        s[x][y]+=w;
        n=max(n,x);
        m=max(m,y);
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            s[i][j]+=s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
        
    int ans=0;
        
    for(int i=r;i<=n;i++)
        for(int j=r;j<=m;j++){
            ans = max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
        }
    
    cout<<ans;
    
    return 0;
}
