#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long LL;

const int N = 1e5+10;
const int M = 2*N;

int n;
int a[M];

int main(){
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    LL maxs=-1e18;
    int depth = 0;
    
    //本题主要难点在于 循环条件的判断上
    //i表示二叉树中具体点的下标故总的判断条件为i<=n
    //j为每层内节点的下标 
    //根据观察得每层第一个元素为2*d 故j<i+(1<<(d-1)) 且j<=n
    for(int d=1,i=1;i<=n;d++,i<<=1){
        LL s=0;
        for(int j=i;j<i+(1<<(d-1)) && j<=n;j++){
            s+=a[j];
        }
        
        if(s>maxs){
            depth = d;
            maxs = s;
        }
    }
    
    printf("%d\n",depth);
    
    return 0;
}