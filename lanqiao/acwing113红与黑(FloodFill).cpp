/*
这类搜索的题掌握了模板之后套进去真的很舒服啊...
真滴秒A
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 30;

char g[N][N];

int w,h;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool st[N][N];
int ans;

void dfs(int x,int y){
	st[x][y] = true;
	
	ans++;
	
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx<0||tx>=h||ty<0||ty>=w||st[tx][ty]||g[tx][ty]=='#')
			continue;
		dfs(tx,ty);
	}
}

int main(){
	cin>>w>>h;
	
	while(w||h){
	    ans=0;
	    
	    memset(st,false,sizeof st);
	    
	    for(int i=0;i<h;i++)
	        cin>>g[i];
	        
	    int sx,sy;
	    
    	for(int i=0;i<h;i++)
	    	for(int j=0;j<w;j++)
	    		if(g[i][j]=='@'){
	    			sx=i;
	    			sy=j;
	    			break;
	    		}		
	
	    dfs(sx,sy);
	
	    cout<<ans<<endl;  
	    
	    
	    cin>>w>>h;
	}
	
	
	return 0;
}