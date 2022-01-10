/*
是一道蛮好的练习搜索、枚举的题
虽然不是最优解 但包含了搜索所需要注意的许多点
一定要理清题意
注意以后 搜索均加入一个st[] 数组去用于判定是否重复
虽然 有些题目不需要 但遇到枚举递归的时候 加入一定是对的！
尤其是在OJ比赛中！！！
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=50;
typedef long long LL;

//s 表示酸度 
//总酸度为每一种配料酸度的乘积
//b 表示苦度
//总苦度为每一种配料苦度的总和
//记酸度为正  苦度为负
int n;
int s[N],b[N];
bool st[N];
int a=1,t;
LL ans=1e9+10;

//u表示当前的配料类别
void dfs(int u){
    if(u==n)
        return;
    
    for(int i=0;i<n;i++){
        if(st[i])
            continue;
        a*=s[i];
        t-=b[i];
        st[i]=true;
        ans = min(ans,(LL)abs(a+t));
        dfs(u+1);
        a/=s[i];
        t+=b[i];
        st[i]=false;
    }

}

int main(){
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>s[i]>>b[i];

    dfs(0);

    cout<<ans<<endl;

    return 0;
}