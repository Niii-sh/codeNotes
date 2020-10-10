/*
关键还是要多思考稍微 转换一下就可以出来了
当然主要还是要靠多积累吧

*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1010;

char g[N][N];
bool st[N][N];
int n;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int dfs(int x,int y,int &total,int &bound){
	st[x][y] = true;
	
	auto is_out = [] (int u,int n)->bool{
		if(u<0||u>=n)
			return false;
		return true;
	};
	
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(!is_out(tx,n)||!is_out(ty,n)||g[tx][ty]=='.'||st[tx][ty]) 
			continue;
		
		bool flag=false;
		
		for(int j=0;j<4;j++){
			int hx = tx + dx[j];
			int hy = ty + dy[j];
			
			if(!is_out(hx,n) || !is_out(hy,n) || g[hx][hy]=='#')
				continue;
			
			flag=true;
		}
		
		total++;
		bound+=flag;
		
		dfs(tx,ty,total,bound);	
	}
}

int main(){
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>g[i];
	
	
	int ans=0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(g[i][j]=='#' && !st[i][j]){
				int total=0,bound=0;
				dfs(i,j,total,bound);
				ans+= total == bound;
			}
		}
	
	cout<<ans;
	
	
	return 0;
}