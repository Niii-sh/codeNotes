/*
理论上要比二分快
但是由于insert操作 和 count 查找操作的原因 会超时 速度也要比二分慢很多
*/

#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<iostream>
using namespace std;

typedef pair<int,int>PII;

const int N = 2500010;

int n,m;
unordered_map<int,PII>S;

int main(){
    cin>>n;
    
    for(int c=0;c*c<=n;c++)
        for(int d=c;c*c+d*d<=n;d++){
            int t = c*c + d*d;
            if(S.count(t)==0)
                S[t] = {c,d};
        }
        
    for(int a=0;a*a<=n;a++)
        for(int b=0;a*a+b*b<=n;b++){
            int t = n-a*a-b*b;
            if(S.count(t)){
                printf("%d %d %d %d\n",a,b,S[t].first,S[t].second);
                return 0;
            }
        }
    
    return 0;
}