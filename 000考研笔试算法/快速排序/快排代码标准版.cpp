/*
快速排序基本思路:
    1.选取一个pivot 
    2.通过一趟排序将排序表划分为独立的两部分 
    使得pivot左边的元素均小于pivot 
        pivot右边的元素均大于pivot
    3.即每一趟可以确定一个元素的位置
Note：
    根据性质3 可以得到 
    1.判断一个序列是否是快速排序的结果时
        可以将该序列先排好序 
        然后与需要判断的序列进行对比 即已经排好序的元素的个数>=趟数 即可能是快速排序的结果
*/

/*
代码：标准代码 王道版
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;

int nums[N];

int partition(int A[],int low,int high){
    int pivot = A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot)
            high--;
        A[low] = A[high];
        while(low<high&&A[low]<=pivot)
            ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

void quicksort(int A[],int low,int high){
    if(low<high){
        int pivotpos = partition(A,low,high);
        quicksort(A,low,pivotpos-1);
        quicksort(A,pivotpos+1,high);
    }
}



int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    
    quicksort(nums,0,n-1);
    
    for(int i=0;i<n;i++)
        printf("%d ",nums[i]);
        
    return 0;
}
    
    
    
    
    
    
    