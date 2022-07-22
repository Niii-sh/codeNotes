/**
    找到区间的交集
    只要这个交集大于2 那么这么之间所有的数都至少有两个相交
    注意 这个题最大坑在于 S 不一定是要连续的 只要求是点集！！！
    贪心(贪心基本上都要排序一次):
        1.首先要区间按intervals[0] 升序 intervals[1]降序
            升序是因为 起点 按顺序 好操作
            降序是因为 保证 相同的情况下 右边的区间长度要更小 因为算的是交集 所以大的肯定是包含小的 优先算小
        2.  分类讨论: 根据排序 x < start 所以讨论关键点在于 y 与 start
            x y start end
            1. y < start 两个区间无交点 start =  y , end = y + 1    ans+=2
            2. y = start 两个区间1交点  start =  y , end = y + 1    ans++
            3. y > start 两个区间2交点  end = y    
 */
class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a,b)->{
            // 升序
            if(a[0] != b[0])
                return a[0] - b[0];
            // 逆序 
            return b[1] - a[1];
        });
        int n = intervals.length;
        int start = intervals[n-1][0];
        int end = start + 1;
        int ans = 2;
        for(int i = n-2;i>=0;i--){
            int x = intervals[i][0];
            int y = intervals[i][1];

            if(y >=end){
                continue;
            }
            else if(y  <  start ){
                start = x;
                end = x + 1;
                ans= ans + 2;
            }
            //  start<y<=end
            else{
                end = start;
                start = x;
                ans++;
            }
        }

        return ans;
    }
}
