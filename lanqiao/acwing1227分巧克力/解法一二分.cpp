/*
由于分的边长越大 则分的块数越少
res+= (h[i]/mid) * (w[i]/mid)
if(res>=k)
即已经满足每一个人都能得到的一块的情况了
那么就满足要求
从边长最长开始二分
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+10;

int h[N],w[N];
int n,k;

bool check(int x){
    int res=0;
    for(int i=0;i<n;i++){
        res+=(h[i]/x)*(w[i]/x);
        if(res>=k)
            return true;
    }
    
    return false;
}

int main(){
    cin>>n>>k;
    
    for(int i=0;i<n;i++)
        cin>>h[i]>>w[i];
    
    int l=0,r=1e5;
    
    while(l<r){
        int mid = l+r+1>>1;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    
    cout<<l;
    
    return 0;
}