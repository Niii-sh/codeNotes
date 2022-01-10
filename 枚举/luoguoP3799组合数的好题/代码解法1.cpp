/*
基本思路：
设四条木棒分别为 a,b,c,d 
则可将符合要求的条件记为(a,b,a+b,a+b)
则又可划分为 a==b 和 a!=b 的两种情况
1.当a==b时 
此时的情况为 C(2,a)*C(2,a+a)
2.当a!=b时
此时的情况为 C(1,a)*C(1,b)*C(2,a+b)

注：C为组合公式的意思
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MOD=1e9+7;
const int N=1e4+10;

typedef long long LL;

int n,len=-1;
LL ans;
LL b[N];

LL C1(LL k){ 
    return k;
}

LL C2(LL k){
    return (k*(k-1))/2 %MOD;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
       int num;
       cin>>num;
       b[num]++;
       len=max(len,num); 
    }

    //cout<< len << endl;
    for(int i=1;i<=len;i++){
        for(int j=i;j<=len;j++){
            //i,j代表两条边 
            if(i==j)
                ans=(ans+C2(b[i])*C2(b[i+i]))%MOD;
            else
                ans=(ans+( C1(b[i])*C1(b[j]) )%MOD*C2(b[i+j]))%MOD;
        }
    }

    cout<< ans <<endl;

    return 0;
}