/*
引理:
    给定a,b, 若d=gcd(a,b)>1 则一定不能凑出最大数
注:因为如果两个数不是互质的话 那肯定有无数个不能凑出的数
    ax+by a>=0.b>=0,的情况下不管a,b如何取值 
    中间肯定会出现无法组成的情况
结论:
    如果a,b均是正整数且互质,那么
    ax+by,x>=0,y>=0 不能凑出的最大数是(a-1)(b-1)-1

*/

#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    cout<<(n-1)*(m-1)-1<<endl;
    return 0;
}