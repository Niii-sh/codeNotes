/*
非常好的一道DP题
由题可得我们可以时使用两种瓷砖去铺墙
分别长方形和 L形
    1       1
    1       1   1
如果要DP需要考虑两种情况 
1.最后是由一块长方形铺满的情况
定义状态为F[] 表示前i列已经铺满的情况
a.
1   1   1   0
1   1   1   0
则这种情况对应的状态就是F[i-1]
b.
1   1   0   0
1   1   1   1
则这种情况对应的状态就是F[i-2]

2.最后一块是由L形铺满的情况
定义状态为G[] 表示前i列已经铺满且i+1列有铺的情况
1   1   0   0
1   1   1   0
对应状态就是G[i-2]
而该种状态可能由两种情况转换而来
a.
1   2   2   0
1   1   0   0
(2表示添加后转换而成的情况)
该种情况G[i-2] 由  G[N-3]   转换而来
b.
1   2   0   0
1   2   2   0
该种情况G[i-2] 则由 F[N-3]  转换而来
则 F[N] = F[N-1] + F[N-2] + 2*G[N-1]
    G[N] = F[N-1] + G[N-1]
    初始化 F[0]=1 G[0]=0 F[1]=G[1]=1;
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
const int MOD=1e4;
typedef long long LL;
LL G[N],F[N];
int n;
int main(){
    cin>>n;
    F[0]=1;
    G[0]=0;
    F[1]=G[1]=1;

    for(int i=2;i<=n;i++){
        F[i] = ((F[i-1] + F[i-2])%MOD + 2*G[i-2] % MOD)%MOD;
        G[i] = (F[i-1] + G[i-1])%MOD;
    }

    cout<<F[n]<< endl;

    return 0;
}