/*
看起来是比较水的一道题
继续递归的条件改为 周围是数字应该就没什么问题了
------
写isdigit的想了一下还是打算直接overload 没必要写个新的函数 
毕竟overload是C++ 的一个很好的特性 重用的话也很容易弄混
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int n,m;
char g[N][N];
int ans;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

bool isdigit(char x){
    if(x>'0'&&x<='9')
        return true;
    return false;
}

void dfs(int x,int y){
    g[x][y]='*';
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=n||ty<0||ty>=m||!isdigit(g[tx][ty]))
            continue;
        dfs(tx,ty);
    }
}

int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++)
        cin>>g[i];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(isdigit(g[i][j])){
                ans++;
                dfs(i,j);
            }
        }

    cout<<ans<<endl;

    return 0;
}