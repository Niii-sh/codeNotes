/*
    冒泡排序优化版:
    即加一个flag标志
    当一趟排序无元素交换时 即代表所有元素已经顺序存放
    
    注意 冒泡排序如果要排成升序列的话
        如果内层j从小到大 那外层i应该从大到小才行
        因为每趟确定的是最大元素 如果i也从大到小的话 
        那么前面的元素就是位置未确定的
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void bobSort(vector<int>&q){
    int n = q.size();
    
    for(int i=n-1;i>0;i--){
        bool flag = false;
        for(int j=0;j<i;j++){
            if(q[j+1]<q[j]){
                flag=true;
                swap(q[j+1],q[j]);
            }
        }
        
        for_each(q.begin(),q.end(),[](int v){
            cout<<v<<' ';
        });
        cout<<endl;
            
        if(!flag)
            return;
    }
    
}

int main(){
    vector<int>q;
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        q.push_back(v);
    }
    
    bobSort(q);
    
    return 0;
}
