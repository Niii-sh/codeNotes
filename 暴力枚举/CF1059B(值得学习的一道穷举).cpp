/*
初步想法是倒退吧 
从结果推出 能否最终将该图染全是'.'
-------
其实不用这么麻烦...
因为想要抵达最终答案一定是将'.'四周一圈染色 
所以遍历过去即可
*/

#include<iostream>  
using namespace std;

const int N=1010;

char g[N][N];   //g为目标数组
char ans[N][N]; //ans为操作数组 通过g与ans的比较 输出答案

int n,m;

/*
(-1,1)   (0,1)   (1,1)
(-1,0)   (0,0)   (1,0)
(-1,-1)  (0,-1)  (1,-1)
*/

int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={1,1,1,0,-1,-1,-1,0};

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            ans[i][j]='.';
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            bool flag=false;
            for(int k=0;k<8;k++){
                int tx=i+dx[k];
                int ty=j+dy[k];
                if(tx<0||tx>=n||ty<0||ty>=m||g[tx][ty]!='#'){
                    flag=true;
                    break;
                }
            }   

            if(!flag){
                for(int k=0;k<8;k++)
                    ans[i+dx[k]][j+dy[k]]='#';
            }
        }
    
    /* 
    cout<<"--------"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }*/

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j]!=ans[i][j]){
                cout<<"NO";
                return 0;
            }
        }

    cout<<"YES";

    return 0;
}