#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 10;

int n;
char g[N][N];
char backup[N][N];

int dx[5] = {-1,0,1,0,0};
int dy[5] = {0,1,0,-1,0};

void turn(int x,int y){
    for(int i=0;i<5;i++){
        int a = x+dx[i];
        int b = y+dy[i];
        if(a<0||a>=5||b<0||b>=5)
            continue;
        g[a][b]^=1;
    }
}

int main(){
    scanf("%d",&n);
    
    while(n--){
        int res = 10;
        for(int i=0;i<5;i++)
            cin>>g[i];
        
        //本题中最难理解的一步
        //之所以op要从0-32枚举
        //是因为本题的特征是下一行的操作由上一行的状态决定
        //所以只要第一行的状态定了 那么就可以决定最终的答案了
        //而第一行有5个开关 每个开关均有开和关两种可能
        //2*2*2*2*2 则有32种可能 所以op从0枚举到32
        for(int op=0;op<32;op++){
            memcpy(backup,g,sizeof g);
            int step = 0;
        //同样为本题最难理解的一步
        //因为op从0-31对应了第一行状态2*2*2*2*2的32种可能
        //0代表不操作 1代表操作 所以每次右移只要是1则代表需要操作
            for(int i=0;i<5;i++)
                if(op>>i&1){
                    step++;
                    turn(0,i);
                }
            
            for(int i=0;i<4;i++)
                for(int j=0;j<5;j++)
                    if(g[i][j]=='0'){
                        step++;
                        turn(i+1,j);
                    }
            
            bool dark = false;
            
            for(int i=0;i<5;i++)
                if(g[4][i]=='0'){
                    dark = true;
                    break;
                }
            
            if(!dark)
                res = min(res,step);
            
            memcpy(g,backup,sizeof g);
            
        }
        
        if(res>6)
            res=-1;
            
        cout<<res<<endl;   
    }
    
    return 0;
}
