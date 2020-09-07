/*
过不了 
但是对于马的多方位循环还是值得注意的
如果以后的题目 DP 或者 记忆化搜索 想不出来的话
就老老实实暴搜吧 
当然 如果遇到 数据量超过100的 基本就不要先考虑暴搜了
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=20+10;

int g[N][N];
int n,m;
int hx,hy;

int dirhx[]={1,-1,2,-2};
int dirhy[]={2,-2,-1,1};

int dx[]={0,1};
int dy[]={1,0};

int ans;

void dfs(int x,int y){
    if(x==n&&y==m){
        ans++;
        return;
    }
    
    

    for(int i=0;i<2;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>n||ty<0||ty>m||g[tx][ty])
            continue;
        
        bool flag=false;
        
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++){
                if((j<2&&k<2)||(j>=2&&k>=2)){
                    int ux=tx+dirhx[j];
                    int uy=ty+dirhy[k];
                    if(ux<0||ux>n||uy<0||uy>m)
                        continue;
                    if(g[ux][uy])
                        flag=true;
                }
            }

            if(!flag)
                dfs(tx,ty);  
        }
        
}

int main(){
    cin>>n>>m>>hx>>hy;
    
    g[hx][hy]=1;

    dfs(0,0);
    
    cout<<ans<<endl;

    return 0;
}