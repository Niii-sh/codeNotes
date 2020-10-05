/*
其实这种题目 见过一次以后 
如果思路想清楚 最后代码推出来也不是很难
还是要多练吧
毕竟7月份的那道题和这道应该是差不多的
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MOD = 100000007;
const int N =1010;

int f[N][N];

int get_mod(int a,int b){
    return (a%b + b)%b;
}

int main(){
    int n,s,a,b;

    cin>>n>>s>>a>>b;
    
    f[0][0] = 1;
    
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            f[i][j] = (f[i-1][get_mod(j-a*i,n)] + f[i-1][get_mod(j+b*i,n)]) % MOD;
    
    cout<< f[n-1][get_mod(s,n)] << endl;
    
    return 0;
}