/**
    法1: set 
    set存储数 
    用set的主要区别在于 省去了暴搜每次x---x+n的重复判断
    
*/
class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> num_set = new HashSet<>();
        
        for(var node: nums)
            num_set.add(node);

        int res=0;

        for(var node:num_set){
            if(num_set.contains(node-1)==false){
                int curNum = node;
                int tmp = 1;

                while(num_set.contains(curNum+1)){
                    tmp++;
                    curNum++;
                }
                res = Math.max(res,tmp);
            }
        }    

        return  res;
    }
}