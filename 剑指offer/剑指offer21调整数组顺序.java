class Solution {
    public int[] exchange(int[] nums) {
        int n = nums.length;
        
        int p=0;
        int q=0;
        int[] res = new int[n]; 
        int[] tmp = new int[n]; //暂时放偶数

        for(int i=0;i<n;i++){
            if(nums[i]%2 == 1)
                res[p++] = nums[i];
            else
                tmp[q++] = nums[i];
        }


        for(int i=0;i<q;i++)
            res[p++] = tmp[i];

        return  res;
    }
}