/*
递归主要是搜索顺序的问题
当然这题同样包含了回溯的知识在里面这是我所不擅长的
值得注意的点时该题中使用了row col dg udg来表示行列 对角线的状态 而不是直接用一个st数组来表示
这样使得题目变得更加清楚是很值得学习的
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 20;

char g[N][N];
bool dg[N],udg[N];	//主对角线 副对角线 是否放置过皇后
bool row[N],col[N];	//行 列 是否放置过皇后
bool st[N][N];	//该点是否放置过皇后

int n;

//当前点的坐标 皇后数
//以列为主顺序进行搜索 当一列搜完则移至下一行
//当行搜索完成时则应相应的输出答案
void dfs(int x,int y,int s){
	//一列搜索完毕进入下一行 并开始每一列的搜索
	if(y==n){
	    x++;
	    y=0;
	    dfs(x+1,0,s);
	}
	//行搜索完毕则由题意可知 此时应输出答案
	if(x==n){
	    if(s==n){
	        for(int i=0;i<n;i++)
	            puts(g[i]);
	        puts("");    
	    }
	   return ;
	}
    
    dfs(x,y+1,s);    
    
	if(!dg[x+y] && !udg[x-y+n] && !row[x] && !col[y] && !st[x][y]){
		g[x][y] = 'Q';
		st[x][y] = true;
		dg[x+y] = udg[x-y+n] = row[x] = col[y] = true;
		dfs(x,y+1,s+1);
		g[x][y] = '.';
		st[x][y] = false;
		dg[x+y] = udg[x-y+n] = row[x] = col[y] = false;
	}

}

int main(){
	scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j] = '.';
    
	dfs(0,0,0);

	return 0;
}