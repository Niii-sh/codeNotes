/*
并查集的初步应用
基本上相当于是把模板换了层皮

操作C 
在 a b 之间连一条边 即合并两个集合

Q1
a b是否在一个连通块 中级 find(a) == find(b)

Q2
查询a中点的数量
唯一需要改进的地方
使用一个cnt数组记录每个连通块的点的数量
在进行合并操作的同时对cnt进行操作
cnt[find(a)]+= cnt[find(b)]
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1e5+10;

int p[N];
int cnt[N];
int n,m;

int find(int x){
    if(x!=p[x])
        p[x] = find(p[x]);
    return  p[x];
}

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        p[i]=i;
        cnt[i]=1;
    }

    while(m--){
        char op[2];
        int a,b;
        cin>>op;

        if(op[0]=='C'){
            cin>>a>>b;
            if(find(a)==find(b))
                continue;
            cnt[find(b)]+=cnt[find(a)];
            p[find(a)]=find(b);
        }
        else if(op[1]=='1'){
            cin>>a>>b;
            if(find(a)==find(b))
                puts("Yes");
            else
                puts("No");
        }
        else{
            cin>>a;
            printf("%d\n",cnt[find(a)]);
        }
    }

    return 0;
}