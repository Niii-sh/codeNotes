/*
审题比较重要
审清题意 确定二分方法 然后再进行二分
在这题中是直接对能量进行二分
l,r事实上代表的是能量的边界值
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;

int h[N];
int maxh;
int n;

bool check(int e){
    for(int i=1;i<=n;i++){
        e = 2*e -h[i];
        if(e>=maxh)
            return true;
        if(e<0)
            return  false;
        
    }
    
    return true;
}

int main(){
    
    cin>>n;
    
     for(int i=1;i<=n;i++)
        cin>>h[i];
    
    maxh = *max_element(h,h+n);
    

    
    //注意此处的二分的l,r 代表不是坐标而是能量
        
    int l=0,r=maxh;
    
       
    while(l<r){
        int mid = l+r>>1;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    
    cout<<r;
    
    return 0;
}