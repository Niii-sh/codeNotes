#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;

const int N=1e5+10;

int n,mod;
LL ans;
int a[N];
int cnt[11][N];

int log_10(int x){
    int res=0;
    while(x){
        x/=10;
        res++;
    }
    return res;
}

void work(){
    for(int i=0;i<n;i++){
        ans+=cnt[log_10(a[i])][(mod-a[i]%mod)%mod];
        for(int j=0,power=1;j<11;j++){
            cnt[j][power*1ll*a[i]%mod]++;
            power=power*10%mod;
        }
    }
}

int main(){
    cin>>n>>mod;

    for(int i=0;i<n;i++)
        cin>>a[i];
    
    //从前往后 一遍
    work();
    memset(cnt,0,sizeof cnt);
    reverse(a,a+n);
    work();

    printf("%lld\n",ans);

    return 0;
}