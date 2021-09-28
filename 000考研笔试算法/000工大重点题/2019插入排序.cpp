/*
    插入排序:
    基本思路: 算是几个排序中难度较大了
    关键是在查找插入位置的过程的同时完成元素的移动  
    即v[j+1]=v[j] 同时用temp保存初始的位置
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void insertion(vector<int>&q){
    int n = q.size();
    for(int i=1;i<n;i++){   //第一个位置默认有序故i从1开始
        int temp = q[i];
        //寻找插入位置的同时确定 进行元素移动
        int j=i-1;
        while(j>=0&&temp<q[j]){
            q[j+1]=q[j];
            j--;
        }
        q[j+1]=temp;
    }    
}

int main(){
    int n;
    cin>>n;
    vector<int>q;
    
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        q.push_back(v);
    }
    
    insertion(q);

    return 0;
}
