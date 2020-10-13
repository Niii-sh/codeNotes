/*
贪心策略:
    将岛屿与海岸线(x轴)上的距离先全部转换的x轴上(在确保y轴可以覆盖的前提下)
    接下来只需要将x轴上的端点排序(右端点为准)   注:由于已经转换过所以此时的l-r为岛屿可以被雷达辐射到的极限范围
    所以接下来比较端点即可 只要处于前一个岛屿极限雷达的右端点以内 即可被同一个雷达辐射到无需ans++
    否则需要再来一个雷达即 ans++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 1e4+10;
struct Seg{
    double l;
    double r;
    bool operator < (Seg &t) const{
        return r<t.r;
    }
}seg[N];

int n,d;
int a[N];

int main(){
    scanf("%d%d",&n,&d);
    
    bool success = false;
    
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(y>d){
            success = true;
            break;
        }
        double len = sqrt(d*d - y*y);
        seg[i].l = x - len;
        seg[i].r = x + len;
        
    }
    
    sort(seg,seg+n);
    
    if(success){
        printf("-1\n");
    }
    else{
        double last = -1e9;
        int ans=0;
        for(int i=0;i<n;i++){
            if(seg[i].l>last){
                last = seg[i].r;
                ans++;
            }
        }
        
        printf("%d",ans);
    }
    
    return 0;
}
