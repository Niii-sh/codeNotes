/*
    冒泡排序优化版:
    即加一个flag标志
    当一趟排序无元素交换时 即代表所有元素已经顺序存放
    
    注意 冒泡排序如果要排成升序列的话
        如果内层j从小到大 那外层i应该从大到小才行
        因为每趟确定的是最大元素 如果i也从大到小的话 
        那么前面的元素就是位置未确定的
*/
/*
    冒泡排序优化
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1E5+10;

void show(vector<int>&q){
    for(int i=0;i<q.size();i++)
        cout<<q[i]<<' ';
    cout<<endl;
}

void bubbleSort(vector<int>&q){
    for(int i=q.size()-1;i>=0;i--){
        bool flag=false;
        for(int j=0;j<i;j++){
            if(q[j]>q[j+1]){
                swap(q[j],q[j+1]);
                flag=true;
            }
            if(!flag)
                return;
            show(q);
        }
    }
}

int main(){
    vector<int>q = vector<int>{3,2,1,5,4};
    bubbleSort(q);
    
    return 0;
}