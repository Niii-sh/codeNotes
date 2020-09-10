/*
基本思路:
看了样例的那个过程就基本明白了
1.将交界处黑白 移至空格处
2.剩余黑棋集体左移填满中间的空行
3.重复上述过程直至结束

n>4的逻辑比较顺递归可以迅速完成
但是n<=4时会比较坑
因为棋子只能两两交换 相邻两两移动 这种题简单是简单但还是要注意审题
最后几种情况不多的话 直接按照样例模拟也是没有任何问题的
独立Debug完成的题+1
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1010;
int n;
char g[N*2];

void print(){
    for(int i=1;i<=2*n+2;i++)
        cout<<g[i];
    cout<< endl;
}

void moveLeft(int u){
    swap(g[u+1],g[2*u]);
    swap(g[u],g[2*u-1]);
}

void dfs(int u){
    if(u==3){
        u++;
        swap(g[u],g[u+4]);
        swap(g[u+1],g[u+5]);
        print();
        swap(g[2],g[8]);
        swap(g[3],g[9]);
        print();
        swap(g[2],g[7]);
        swap(g[3],g[8]);
        print();
        swap(g[1],g[7]);
        swap(g[2],g[8]);
        print();
        return;
    }
    swap(g[u],g[2*u+1]);
    swap(g[u+1],g[2*u+2]);
    print();

    if(u>4){
        moveLeft(u);
        print();
    }
    dfs(u-1);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        g[i]='o';
        g[i+n]='*';
    }    
    g[2*n+1]=g[2*n+2]='-';
    
    print();
    dfs(n);

    return 0;
}