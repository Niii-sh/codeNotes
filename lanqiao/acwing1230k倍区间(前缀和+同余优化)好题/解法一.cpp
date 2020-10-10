/*
u1s1蓝桥杯是真的很喜欢考到同余这个知识点
这已经是我做到的第3题了
非常巧妙 也比较难以理解

*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long LL;

const int N = 1e5+10;

LL s[N],cnt[N];
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        s[i]+=s[i-1];
    }
    
    LL res=0;
    
    cnt[0]=1;
    
    for(int i=1;i<=n;i++){
        res+=cnt[s[i]%k];
        cnt[s[i]%k]++;
    }
    
    cout<<res;
    
    return 0;
}