/*
解法二:位运算
递归+位运算就显得非常优雅
当然 位运算在解决大数据问题的时候也有很重要的作用
基本思路:
    基本上与递归差不多
    精华在for循环部分
    用1<<p 代表pow(2,i) 从高位开始寻找刚好小于u的值
    用cur记录当前所处的位数
    cur!=1 如果不是最低位 即不是2(0) 则打印 "+"
    判断p
    如果p>1 打印"2("  内层递归后 打印")"
    
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

void dfs(int u){
    int cur=0;
    switch(u){
        case 0: 
            printf("2(0)");
            break;
        case 1:
            printf("2");
            break;
        default:
            for(int p=14;p>=0;p--){
                if(u&(1<<p)){       //判断最高是否为1 即分解2(p)次
                    if(cur)
                        printf("+");
                    else
                        cur++;
                    if(p!=1&&p!=0){
                        printf("2(");
                        dfs(p);
                        printf(")");
                    }
                    else
                        dfs(p);
                }
            }
    }

    return;
}

int main(){
    int n;
    cin>>n;
    dfs(n);
    return 0;
}