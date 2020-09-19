/*
偏暴力的一道题 
有点搜索的感觉 但这还不算是 什么搜索吧
挺简单但是 还是被小细节卡了很久
为什么isRetangle 那里不能用一个一个for 循环直接解决呢... 
哎 算了 大致意思明白就好 还是不要在这种地方纠结太久了 
到校第一题 希望可以一直坚持下去！！ 华师大加油！！！

申请题意这题基本就没问题 
主要分为两个步骤 
1.判断是否会摆放错误如果摆放错误直接输出 函数结束
2.如果拜访正确那么统计军舰数量 此处选用Flood Fill 算法即可
    tips: 可使用染色的原理 直接同一连接块染为统一颜色 则无需再用st 数组 节约了空间
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;

char g[N][N];
int n,m;
int ans;

bool isRectangle(int x,int y){
    int tmp=0;
    tmp+= g[x][y] == '#';
    tmp+= g[x+1][y] == '#';
    tmp+= g[x][y+1] == '#';
    tmp+= g[x+1][y+1] == '#';
    //如果tmp==3 代表 摆放错误 
    return tmp==3;
}


void dfs(int x,int y){
    g[x][y]='1';
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=n||ty<0||ty>=m||g[tx][ty]!='#')
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
            if(isRectangle(i,j)){
                puts("Bad placement.");
                return 0;
            }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='#'){
                ans++;
                dfs(i,j);
            }

    printf("There are %d ships.",ans);

    return 0;
}
