class Solution {
    const int MOD = 1e9+7;
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        long long a=0,b=1,c;

        for(int i=2;i<=n;i++)
        {
            c=(a+b)%MOD;
            a = b;
            b = c;
        }
        
        int res = c%MOD;

        return res;
    }
};