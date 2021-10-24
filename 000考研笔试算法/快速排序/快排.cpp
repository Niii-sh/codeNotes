#include<iostream>
using namespace std;

const int N=1e5+10;
int q[N];

void quickSort(int nums[], int left, int right){
        if (left > right) return;
        int pivot = nums[left];
        int l = left, r = right;
        while (l < r){
            while (l < r && nums[r] >= pivot) r--;
            while (l < r && nums[l] <= pivot) l++;
            if (l < r){
                int x = nums[l];
                nums[l] = nums[r];
                nums[r] = x;
            }
        }
        nums[left] = nums[l];
        nums[l] = pivot;
        quickSort(nums, left, l - 1);
        quickSort(nums, l + 1, right);
}
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",&q[i]);
    
    quickSort(q,0,n-1);
    
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
    
    return 0;
}
