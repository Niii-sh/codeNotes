/*
显然是一个递推的问题
3个瓶盖换一瓶饮料
显然就是 买3送1 的意思咯 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int n; 
int ans;

int main(){
    cin>>n;
    
    int t=0;    //存储每次剩余的瓶盖数 
    
    while(n){
        ans+=n;
        t+=n;
        n=t/3;
        t%=3;
        
    }
    
    cout<<ans;
    
    return 0;
}