/*
二分的初步应用
思路很简单 但真的有太多太多细节了
二分真的只能靠熟练
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;

int a[N];

int n,q;

int main(){
    cin>>n>>q;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    while(q--){
        int k;
        cin>>k;
        
        //寻找左端点
        auto find_l =[] (int a[],int x)->bool{
            int l=0,r=n-1;
            while(l<r){
                int mid = l+r>>1;
                if(a[mid]<x)
                    l=mid+1;
                else
                    r=mid;
            }
            
            if(a[l]==x){
                cout<<l<<' ';
                return true;
            }
            else{
                cout<<"-1 -1"<<endl;
                return false;
            }
            
        };
        
        if(find_l(a,k)){
            auto find_r =[] (int a[],int x)->bool{
                int l=0,r=n-1;
                while(l<r){
                    int mid = l+r+1>>1;
                    if(a[mid]<=x)
                        l=mid;
                    else
                        r=mid-1;
                }
                cout<<r<<endl;
            }(a,k);
        }
        
    }
    
    
    return 0;
}