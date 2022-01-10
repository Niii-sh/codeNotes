/*
比较基础的一道搜索题
但是这种单向搜索虽说简单 但还是有许多需要注意的时候
尤其是进行递归循环的时候 采用传统的dx dy 位移偏量来循环了
最后 以后遇到这种题目的话
如果数据范围比较小的话还是用搜索会逻辑清晰一些也好Debug许多
用递推虽然快了 但太难了发现错误了 这道之前在递推上卡了许久
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=110;

char g[N][N];
int n,m,k;
int ans=0;

//x,y表示位置 dist表示当前已走过的距离
//dir 表示方向 
//0 表示向下 即 x++
//1 表示向右 即 y++
void dfs(int x,int y,int dist,int dir){
    if(dist==k){
        ans++;
        return;
    }


    //向下
    if(dir==0){
        x++;
        if(x>=0&&x<n&&g[x][y]=='.')
            dfs(x,y,dist+1,0);
    }

    //向右
    if(dir==1){
        y++;
        if(y>=0&&y<m&&g[x][y]=='.')
            dfs(x,y,dist+1,1);
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j]=='.'){
                dfs(i,j,1,0);
                dfs(i,j,1,1);
            }
        }

    if(k==1)
        ans/=2;

    cout<< ans << endl;

    return 0;
}