/*
基本思路:
分治+递归
详情见分析

四种方块
第一种  第二种  第三种  第四种
    1   2       3   3   4   4
1   1   2   2       3   4

分治一直掌握的不太熟练 
其实这题和归并排序很像 
还是需要多练
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define ul dfs(a+s-1,b+s-1,a,b,s);  //递归左上角
#define ur dfs(a+s-1,b+s,a,b+s,s);  //递归右上角
#define dl dfs(a+s,b+s-1,a+s,b,s);  //递归左下角
#define dr dfs(a+s,b+s,a+s,b+s,s);  //递归右下角


int k,x,y;

//x,y表示当前所要填的方格的位置
//a,b表示当前所要填的方格左上角的位置
//s  表示当前所要填方格的大小
void dfs(int x,int y,int a,int b,int s){
    if(s==1)    //分治至最终只有一块方格 return
        return;
    
    // 由于题目所给的边长为2(k) 
    // 所以每次s>>1 即代表边长减少1
    s>>=1;

    //如果左上角有空 
    //用第一种方块填补
    //详细见具体的分析过程
    //注: 不管是哪种情况打印时都要+s
    //因为a,b 是从左上角开始进行分治 
    //所以s 相当于是填补了 分治过程中偏移量
    //+1 -1 才是真正决定每个微小划中的递归位置
    //比较乱 但刚开始就先这么理解吧... f
    //分治是薄弱项 要多刷
    if(x-a<s&&y-b<s){
        printf("%d %d 1\n",a+s,b+s);
        dfs(x,y,a,b,s);
        ur
        dl
        dr
    }
    

    //右上角
    if(x-a<s&&y-b>=s){
        printf("%d %d 2\n",a+s,b+s-1);
        ul
        dfs(x,y,a,b+s,s);
        dl
        dr
    }

    //左下角
    if(x-a>=s&&y-b<s){
        printf("%d %d 3\n",a+s-1,b+s);
        ul
        ur
        dfs(x,y,a+s,b,s);
        dr 
    }

    //右下角
    if(x-a>=s&&y-b>=s){
        printf("%d %d 4\n",a+s-1,b+s-1);
        ul
        ur
        dl
        dfs(x,y,a+s,b+s,s);
    }
}

int main(){
    cin>>k>>x>>y;

    dfs(x,y,1,1,1<<k);

    return 0;
}