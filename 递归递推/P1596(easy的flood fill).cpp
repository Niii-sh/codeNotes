/*
flood Fill + 染色法
显然是之前某道题的复刻
这种题之后之后就要增加准确率和速度
争取一次性A掉

'W'表示水   '.'表示旱地
注意这题斜着也是可以相连的
(-1,1)  (0,1)   (1,1)
(-1,0)  (0,0)   (1,0)
(-1,-1) (0,-1)  (1,-1)
即如上图所示的坐标方位
故 dx={-1,0,1,1,1,0,-1,-1};
   dy={1,1,1,0,-1,-1,-1,0};
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=110;
char g[N][N];
int ans;
int n,m;

int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {1,1,1,0,-1,-1,-1,0};

void dfs(int x,int y){
    g[x][y]='*';
    for(int i=0;i<8;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=n||ty<0||ty>=m||g[tx][ty]!='W')
            continue;
        dfs(tx,ty);
    }
}

int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++)
        cin>>g[i];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='W'){
                ans++;
                dfs(i,j);
            }
    cout<<ans<<endl;
    return 0;
}