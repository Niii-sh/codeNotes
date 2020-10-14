/*
还是要考虑好状态
u代表当前所枚举的步数
即当前所在的位置 那么就一定是way[u] = i 了
每次传入i+1 作为start 则自然保证了 后面所枚举的数比前面大
*/
/*
递归基本思路:
    与排列型枚举主要不同在于枚举时 是否重复不看顺序 只要数相同就算一种情况
    基本解决思路:
        每次枚举的时候规定后一个数一定要大于前一个数
        保证了不重复 同时确保了字典序
    关于细节:
        u表示当前枚举的步数 start表示每一个序列的枚举起点
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 30;

int n,m;
int way[N]; //记录每次枚举所记录的数

void dfs(int u,int start){
    if(u==m+1){
        for(int i=1;i<=m;i++)
            printf("%d ",way[i]);
        printf("\n");
        return;
    }
    
    for(int i=start;i<=n;i++){
        way[u] = i;
        dfs(u+1,i+1);
        way[u] = 0;
    }
    
}
    
    

int main(){
    scanf("%d%d",&n,&m);
    
    dfs(1,1);
    
    return 0;
}