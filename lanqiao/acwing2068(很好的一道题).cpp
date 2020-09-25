/*
考虑第一个问题
a[i] 和 a[j] 所拼接而成的数什么
(假定i<j)
    则 ans = a[i]*10^(log10a[j])+a[j]
    (就是将a[i]整体向前平移)
    ans 为 k 的倍数 及 a[i]*10^(log10a[j])为k的数 a[j]为k的倍数
    所以即可将 问题拆解
    然而注意到a[i]*10^(log10a[j])%k 必定是小于k
    将a[i]*10^(log10a[j])%k存储 即可避免后续的重复计算
    所以可以开一个cnt数组 cnt[i][j] 记录之前遍历过的所有数中,乘10^i后模k的结果为j的数的个数
    对于所有的a[i] 累加cnt[log10a[i]][(k-a[i]%k)%k]即可
    但这只能求出i<j的情况
    如果要求出所有答案只需从后往前走一遍即可(取巧则可以直接用reverse将数组反转)
有些记忆化搜索的感觉
思路很巧妙
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1e5+10;

int n,mod;
LL ans;
int a[N];
int cnt[11][N]; //因为Ai<=10^9 所以最多只用乘以10^10 第一维开11即可

//计算Log10X的结果
int log_10(int x){
    int res=0;
    while(x){
        x/=10;
        res++;
    }
    return res;
}

//计算结果
int work(){
    for(int i=0;i<n;i++){
        ans+=cnt[log_10(a[i])][(mod-a[i]%mod)%mod];
        for(int j=0,power=1;j<11;j++){
            cnt[j][1ll*a[i]*power%mod]++;
            power=power*10%mod;
        }
    }
}

int main(){
    cin>>n>>mod;

    for(int i=0;i<n;i++)
        cin>>a[i];
    
    work();

    memset(cnt,0,sizeof cnt);

    reverse(a,a+n);

    work();

    cout<<ans<<endl;

    return 0;
}