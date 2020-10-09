#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 2500010;

int n;

struct Sum{
    int s,c,d;
    
    bool operator < (Sum &t) const{
        if(s!=t.s)
            return s<t.s;
        if(c!=t.c)
            return c<t.c;
        return d<t.d;
    }
}sum[N];

int main(){
    cin>>n;
    
    int p=0;
    
    for(int c=0;c*c<=n;c++)
        for(int d=c;c*c+d*d<=n;d++){
            sum[p++] = {c*c+d*d,c,d};
        }    
        
    sort(sum,sum+p);
        
    for(int a=0;a*a<=n;a++)
        for(int b=0;a*a+b*b<=n;b++){
            int t = n-a*a-b*b;
            int l=0,r=t-1;
            while(l<r){
                int mid = l+r>>1;
                if(sum[mid].s<t)
                    l=mid+1;
                else
                    r=mid;
            }
            
            if(sum[l].s==t){
                printf("%d %d %d %d\n",a,b,sum[l].c,sum[l].d);
                return 0;
            }
        }
        
    
    return 0;
}