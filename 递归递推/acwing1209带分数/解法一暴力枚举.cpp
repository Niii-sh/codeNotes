/*
其实真正做了才发现这道题真的不算难 
之前是我把这个题想的太难了
暴力枚举的思路还是很清晰的
*/
/*
递归基本思路:
    在全排列的基础上加以改进 
    一个全排列就够了..
    在一个全排列的基础上加以判断不然会超时
    n = a + b/c;
    则可转换为
    c*n = c*a + b
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

bool st[10]; //判重数组
int way[10];
int n;
int ans;

int calc(int l,int r){
    int res=0;
    for(int i=l;i<=r;i++){
        res*=10;
        res+=way[i];
    }
    
    return res;
}

void dfs(int u){
    if(u>=10){
        for(int i=1;i<=7;i++)
            for(int j=i+1;j<=8;j++){
                int a=calc(1,i);
                int b=calc(i+1,j);
                int c=calc(j+1,9);
                if(c*n == c*a + b )
                    ans++;
            }
            
        return ;
    }    
    
    for(int i=1;i<=9;i++){
        if(!st[i]){
            way[u] = i;
            st[i]=true;
            dfs(u+1);
            st[i] = false;
        }
    }
    
}

int main(){
    scanf("%d",&n);
    
    dfs(1);
    
    printf("%d",ans);
    
    return 0;
}
