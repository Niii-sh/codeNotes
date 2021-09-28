/*
    斐波那契数列:
    迭代和递归两种
    迭代线性O(n) 又可分正常迭代 滚动数组 还有最牛B的快速幂但不用掌握
    递归 O(2^n) 而且这个还比较容易忘记...
*/
#include<iostream>
#include<algorithm>
using namespace std;

//迭代写法
//n表示最终项
long fib(int n){
    int a=1,b=1;
    if(n>=1)
        printf("%d ",a);
    if(n>=2)
        printf("%d ",b);
    long c;
    for(int i=3;i<=n;i++){
        c=a+b;
        printf("%ld ",c);
        a=b;
        b=c;
    }
}

//递归写法
long fibt(int n){
   if(n<=2)
        return 1;
    return fibt(n-1)+fibt(n-2);
}

int main(){
    cout<<fibt(10);
    return 0;
}