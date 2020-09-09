/*
注：只能从标号小的爬到标号大相邻蜂房
根据题目的意思 
1.如果在上 则只能往右下走 
i+1 或 j+1
2.如果在下 则只能往 右与右上走
j+1 或 i-1,j+1

定义 dp[][]
if(i==1)
    dp[][] = dp[i][j-1] + dp[i+1][j-1]
if(i==2)
    dp[][] = dp[i][j-1] + dp[i-1][j]   


由于该题 起点和终点不是固定的所以采用一个小技巧(也算是灵光乍现吧)
把2维的数组展平即可
则
下 +1 右 +2 右下+3 
上 -1 左 -2 左上-3
定义 dp[]
if(u%2==1)  //奇数则代表在上
    dp[] = dp[u-2] (左边) + dp[u-1] (左下)
if(u%2==0)
    dp[] = dp[u-1](上面) + dp[u-2](左边)
可以惊喜的发现两种情况是一样的所以和2为1即可

另外此题需要用到高精度 和 重载
虽然简单但考验基本的代码能力
当然本题也是第一次独立推导完成的DP题 还是很有成就感
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

typedef long long LL;

const int N=1000*2+10;
int m,n;

vector<int>add(vector<int>&a,vector<int>&b){
    vector<int>c;
    
    if(a.size()<b.size())
        swap(a,b);
    
    int t=0;
    for(int i=a.size()-1,j=b.size()-1;i>=0;i--,j--){
        if(j>=0)
            t+=b[j];
        t+=a[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t)
        c.push_back(1);
    reverse(c.begin(),c.end());
    return c;
}

struct Node{
    vector<int>q;
    Node operator+ (Node&t){
        Node node;
        node.q=add(q,t.q);
        return node;
    }
}dp[N];

int main(){
    cin>>m>>n;

    dp[m].q.push_back(1);

    for(int i=m;i<=n;i++){
        Node tmp = dp[i-1] + dp[i-2];
        dp[i] = dp[i] + tmp;
    }

    for(int i=0;i<dp[n].q.size();i++)
        cout<<dp[n].q[i];


    return 0;
}
