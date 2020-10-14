#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 50;
typedef long long LL;

LL a[N];
int n;

int main(){
    scanf("%d",&n);
    
    a[0] = 0;
    a[1] = 1;
    
    if(n==1)
        printf("0");
    else if(n==2)
        printf("0 1");
    else{
        printf("0 1 ");
        for(int i=2;i<n;i++){
            a[i] = a[i-1] + a[i-2];
            printf("%d ",a[i]);
        }
        
    }
    
    
    return 0;
}