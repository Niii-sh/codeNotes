/*
贪心策略:
    由于中间不管股票如何交易 
    最终的最大收益肯定是将每一次后减前的值相加 即可
    所以只要判断后面比前面大然后做差即可
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1e5+10;

int a[N];
int n;

int main(){
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    int b=a[0];
    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i]>b)
            ans+= a[i]-b;
        b =  a[i];
    }
    
    printf("%d",ans);
    
    return 0;
}