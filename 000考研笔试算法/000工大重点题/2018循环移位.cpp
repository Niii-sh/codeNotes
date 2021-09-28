/*
    循环移位:
    不需要理解成组成里的那种循环移位
    就是把数从右移左就完事了 如果是循环右移的话
    
    基本思路:
    这个问题要点在于移动的话 会有元素溢出
    右移则要将溢出的元素补到左边 左移则要溢出的元素补到右边
    如果是要右移的话 
    先建立一个原数组的副本 
    然后用m%k计算出将会溢出的位数 因为有可能出现右移移回原处的情况 
    就好像转了360°回到回原地一样
    然后进行移位操作
    时间复杂度O(n)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//n表示a的长度 k表示需要循环右移的位数 
void rCycleShift(int a[],int n,int k){
    int *bk = new int[k];
    int i,m;
    for(int i=0;i<n;i++)
        bk[i]=a[i];         //直接复制完整的数组
    
    m=k%n;  //m表示将会被覆盖的位数
    
    for(int i=0;i<n;i++){
        if(i+m<n)
            a[i+m]=bk[i];   //右移后不会溢出
        else    //会溢出则将其填补到右边 其应该属于的位置
            a[i+m-n]=bk[i]; //i+m-n 反过来的话就是负了 显然不对
    }
    
    for_each(a,a+n,[](int i){
        cout<<i<<' ';
    });
    
    cout<<endl;
    
    delete []bk;
}

int main(){
    int n;
    cin>>n;
    
    int a[n];
    
    for(int i=0;i<n;i++){
          cin>>a[i];     
    }
    
    rCycleShift(a,n,3);
    
    return 0;
}
