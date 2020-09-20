/*
这道题的2(N)的暗示还是比较明显的
应该就是用数组来存储二叉树了
左儿子2*x  右儿子 2*x+1

本题的递归建树规则:
1.根节点类型与S串的类型相同
2.如果S>1 将其分为左右等长的S1 S2并递归构造

全0 即该节点为B
全1 即该节点为I
有0有1 为F

基本思路：从两边开始向中间递归
虽然模模糊糊有些理解就是这种但具体的还是有那么些区别 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int M=11;
const int N=1<<11;

char tree[N];

string s;
int n;


void PostOrderCreate(int l,int r){
    //后序遍历建树
    //左右根
    if(l<r){
        int mid= l+r>>1;
        PostOrderCreate(l,mid);
        PostOrderCreate(mid+1,r);
    }

    bool tb=false,ti=false;
    
    for(int i=l;i<=r;i++){
        if(tree[i]=='1')
            ti=true;
        if(tree[i]=='0')
            tb=true;
    }

    if(ti&&tb)
        printf("F");
    else if(ti)
        printf("I");
    else if(tb)
        printf("B");
}

int main(){
    cin>>n>>tree+1;
    PostOrderCreate(1,(1<<n)); 
    return 0;
}