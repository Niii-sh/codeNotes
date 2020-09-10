/*
此题斐波那契数据极大 且需要取模
所以采用矩阵快速幂
1.构造矩阵
2.使用快速幂进行求解
(详细见解析中)

另外注意memcpy  sizeof 那里一定要填传函数内的数组
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long LL;

const int N=3;

int n,m;

void mul(int c[],int a[],int b[][N]){
    int tmp[N] = {0};
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            tmp[i] = (tmp[i]+(LL)a[j]*b[j][i])%m;

    memcpy(c,tmp,sizeof tmp);
}

void mul(int c[][N],int a[][N],int b[][N]){
    int tmp[N][N]={0};
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                tmp[i][j] = (tmp[i][j]+(LL)a[i][k]*b[k][j]);
    memcpy(c,tmp,sizeof tmp);
}

int main(){
    cin>>n>>m;

    int F1[N] = {1,1,1}; //f1 , f2 , s1
    int A[N][N] = {
        {0,1,0},
        {1,1,1},
        {0,0,1}
    };  

    n--;

    while(n){
        if(n&1)
            mul(F1,F1,A); //res = res*A
        mul(A,A,A); //A=A*A
    }

    cout<<F1[2];


}