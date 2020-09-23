#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1e4+10;

int n,m;

int p[N];

int find(int x){
    if(x!=p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main(){ 
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        p[i]=i;
    
    while(m--){
        int x,y,z;
        cin>>z>>x>>y;
        if(z==1){
            p[find(x)]=find(y);
        }
        else{
            if(find(x)==find(y))
                puts("Y");
            else
                puts("N");
        }
    }
    
    return 0;
}