/*
    折半查找 或者说是二分
    二分的基本思路:
    由于应付考研所以更需要重视的是规范而非细节
    mid = (low+high)/2 (下取整 参考考研一般代码的标准) 
    a[mid] > target
        high = mid-1
    a[mid] < target
        low = mid+1;
    else
        return

    关于折半查找树 的一点相关的笔记
    在 mid=(low+high)/2 (下取整的前提下有如下的性质)
    1.对于任何一个结点有 右子树结点数-左子树结点数 = 0或1
    2.折半查找树 一定是 平衡查找树
    3.判定树关键字:左<中<右 满足二叉排序的定义
    4.失败结点:n+1个 = 成功结点的空链域数  
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target)
                high = mid-1;
            else if(nums[mid]<target)
                low = mid+1;
            else
                return mid;
        }

        return -1;
    }
};