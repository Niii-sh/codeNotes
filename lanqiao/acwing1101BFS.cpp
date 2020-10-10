/*
关键点在于想到用st数组记录每一步的步数
如果该步可走 则有 st[x][y] = st[t.x][t.y] + 1;
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 210;

int T,r,c;

struct Node{
	int x;
	int y;
};

char g[N][N];
int st[N][N];

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};



int main(){
	cin>>T;
	
	while(T--){
		int r,c;
		cin>>r>>c;
		
		
		
		for(int i=0;i<r;i++)	
			cin>>g[i];
	
		int sx,sy;
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				if(g[i][j]=='S'){
					sx=i;
					sy=j;
					break;
				}
			}
		
		memset(st,0,sizeof st);
		
		queue<struct Node>q;
		q.push({sx,sy});
		st[sx][sy] = 1;
	
	   bool flag=false;
	   
		while(q.empty()==false){
			auto t = q.front();
			q.pop();
			if(g[t.x][t.y]=='E'){
			    printf("%d\n",st[t.x][t.y]-1);
			    flag=true;
			}
			for(int i=0;i<4;i++){
				int x = t.x + dx[i];
				int y = t.y + dy[i];
				if(x<0||x>=r||y<0||y>=c||st[x][y]||g[x][y]=='#')
					continue;
				q.push({x,y});
				st[x][y]=st[t.x][t.y]+1;
			}
			
		}
		if(!flag)	
			printf("oop!\n");	
	}
	
	return 0;
}