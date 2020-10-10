#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 110;

char g[N][N][N];

int dist[N][N][N];

struct Node{
	int x,y,z;
};

int dx[6] = {0,1,-1,0,0,0};
int dy[6] = {-1,0,0,1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int main(){
	int l,r,c;
	
	cin>>l>>r>>c;
	
	while(l||r||c){
		memset(dist,0,sizeof dist);
		int sx,sy,sz,ex,ey,ez;
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++){
					cin>>g[i][j][k];
					auto &t = g[i][j][k];
					if(t=='S'){
						sx=i;sy=j;sz=k;
					}
					
					if(t=='E'){
						ex=i;ey=j;ez=k;
					}
				}
		
		queue<struct Node>q;
		
		q.push({sx,sy,sz});
		
		while(q.empty()==false){
			auto t = q.front();
			q.pop();
			for(int i=0;i<6;i++){
				int x = t.x + dx[i];
				int y = t.y + dy[i];
				int z = t.z + dz[i];
				
				auto is_out = [] (int u,int n)->bool{
					if(u<0||u>=n)
						return false;
					return true;
				};
				
				if(!is_out(x,l) || !is_out(y,r) || !is_out(z,c) || g[x][y][z] == '#' || dist[x][y][z])
					continue;
				
				if(x==ex && y==ey && z==ez){
					dist[x][y][z] = dist[t.x][t.y][t.z]+1;
					printf("Escaped in %d minute(s).\n",dist[t.x][t.y][t.z]+1);
				}
				
				dist[x][y][z] = dist[t.x][t.y][t.z]+1;
				
				q.push({x,y,z});
			}
		}
		
		if(!dist[ex][ey][ez])
				printf("Trapped!\n");
		
		cin>>l>>r>>c;
	}	
	
	return 0;
}