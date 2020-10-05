/*
其实思路也不难
但需要注意的点比较多 很容易坑
基本思路:
用sa sc数组分别记录 a c 的出现次数
数组的下标视为数值 值为出现次数
所以算ans时 只需要 ans+=(sa[b[i]-1)*(sc[N-1]-sc[b[i]])
                    (小于bi 出现的次数 乘以 大于bi出现的次数)
注意！！！:
如果开的数组大小为N 那么一定一定只能算到N-1
否则出现的值将无法掌控 很难很难调试
一定要注意越界的情况！！！
*/

#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=1e5+10;

LL sa[N],b[N],sc[N];
int n;

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        LL a;
        cin>>a;
        sa[a]++;
    }
    
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        b[i]=v;
    }
    
    for(int i=0;i<n;i++){
        LL c;
        cin>>c;
        sc[c]++;
    }
    
    for(int i=1;i<=N-1;i++){
        sa[i]+=sa[i-1];
        sc[i]+=sc[i-1];
    }
    
    
    LL ans=0;
    
    for(int i=1;i<=n;i++){
        ans+=(LL)(sa[b[i]-1]*(sc[N-1]-sc[b[i]]));  
    }
    
    cout<<ans;
    
    return 0;
}