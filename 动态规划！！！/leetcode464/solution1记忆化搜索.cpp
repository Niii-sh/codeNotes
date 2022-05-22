class Solution {
public:
    /*
        记忆化搜索的hashmap 
        用来记录选择了哪些树的情况 
        当前玩家的胜负 用以减少时间复杂度
    */
    unordered_map<int,bool>memo;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        /*
            如果所有数加起来都小于小于 desiredTotal 则直接返回false 两边都不能没法
            这里用的是等差求和
        */
        if((1+maxChoosableInteger)*(maxChoosableInteger)/2<desiredTotal){
            return false;
        }
        return dfs(maxChoosableInteger,0,desiredTotal,0);
    }

    bool dfs(int maxChoosableInteger,int usedNumbers,int desiredTotal,int currentTotal){
        //如果当前这种取数状态 还没有判断过
        if(!memo.count(usedNumbers)){
            bool res = false;
            for(int i=0; i<maxChoosableInteger;i++){
                /*
                    usedNumbers>>i 遍历循环每一个数 这里是状态压缩 二进制的一个位置代表一个数
                    (usedNumbers>>i) & 1 : 判断i+1是否已经被访问
                    usedNumbers | (1<<i) 把i+1 标记为访问
                */
                if(((usedNumbers>>i)&1) == 0){
                    // 如果取得数 加上 当前值已经大于期望值 则判断为胜
                    if(i+1+currentTotal>=desiredTotal){
                        res = true;
                        break;                      
                    }
                    if(!dfs(maxChoosableInteger,usedNumbers|(1<<i),desiredTotal,currentTotal+i+1)){
                        res = true;
                        break;
                    }
                }
            }
            //将当前这种情况 进行赋值 
            memo[usedNumbers] = res;
        }
        return memo[usedNumbers];
    }
};
