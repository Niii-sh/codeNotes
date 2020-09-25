/*
基本思路：
    dfs 模拟题目的意思应该就可以解决
算是送分的一道题了
记得用long long
*/

#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

LL n;

void dfs(LL u){
    if(u==0)
        return;
    cout<<u<<' ';
    dfs(u/2);
}

int main(){
    cin>>n;
    dfs(n);
    return 0;
}