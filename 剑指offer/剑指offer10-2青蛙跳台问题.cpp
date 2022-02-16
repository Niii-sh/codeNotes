/*
    基本思路:动态规划
    dp的值 表示跳到每一层的方法数
    dp[10]=n  即表示跳到第10层的方法数 n
    从n-1阶 到 n阶 有一种跳法
    从n-2阶 到 n阶 有一种跳法
    即 dp[n] = dp[n-1] + dp[n-2]
*/
class Solution {
    const int N = 110;
    const int MOD = 1e9+7;
public:
    int numWays(int n) {
        if(n==0)
            return 1;
        
        if(n==1)
            return 1;

        vector<int>dp(N,0);        
        //定义初始化状态
        dp[0] = 1; 
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2])%MOD; 
        }



        return dp[n]%MOD;
    }
};