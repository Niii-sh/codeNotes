#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N =60;
int n,m;
char g[N][N];


int w[N];
int b[N];
int r[N];

int cost(int col,char ch){
    int sum=0;
    for(int i=1;i<=m;i++)
        if(g[col][i]!=ch)
            sum++;
    return sum;
}

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)    
            cin>>g[i][j];
    
    int ans=1e9;

    //前缀和预处理

    for(int i=1;i<=n;i++){
        w[i]+=cost(i,'W');
        w[i]+=w[i-1];
        b[i]+=cost(i,'B');
        b[i]+=b[i-1];
        r[i]+=cost(i,'R');
        r[i]+=r[i-1];
    }


    for(int i=1;i<=n-2;i++) //i为白色结束的位置
        for(int j=i+1;j<=n-1;j++)   //j为蓝色结束的位置
            ans=min(ans,w[i]+(b[j]-b[i])+(r[n]-r[j]));

    cout<<ans;

    return 0;
}