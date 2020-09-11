/*
基本思路:
将每次的串 划分为原串和操作串
可以发现之后生成的操作串
即为原串最后一位动
其余所有位置右移得到
1.cow
2.  wco
3.    ocowwc

分治过程:
n,tmp 记录寻找过程中的位置
tmp 初始值为 n左边最靠近的字符串末尾的位置
while(tmp>=len) 只要没分治到最初始的位置
判断 n 与 tmp 的关系
1.n>=tmp
    意味着答案在操作串中
    n=n-tmp 将操作串左移
        n==0?
        1.n==0 意味着位于旋转点(分治交界处的位置)
          不需要左移tmp位只需 n=tmp-1即可
        2.n!=0
            由于中间还有一个旋转点 
            所以左移之后还要减去旋转点的位置
tmp=>>1
进入下一层分治
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long LL;

string str;
LL n,len;

int main(){
    cin>>str>>n;
    len=str.size();
    
    LL tmp=len;
    while(tmp<=n)
        tmp<<=1;
    
    tmp>>=1;

    n-=1;

    while(tmp>=len){
        if(n>=tmp){
            n-=tmp;
            if(!n)
                n=tmp-1;
            else
                n-=1;
        }
        tmp>>=1;
    }

    cout<<str[n%len]<< endl;

    return 0;
}