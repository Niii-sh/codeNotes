/*
DP问题的优化本质上是代码的等价变形
目前对于DP优化原理还不是很理解 这种优化的方法暂且先放一放吧
这里优化的关键是
用maxv来存储满足 a[i] > b[k]的f[i - 1][k] + 1的前缀最大值。
因此可以直接将maxv提到第一层循环外面，减少重复计算，此时只剩下两重循环。
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N];
int f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);

    for (int i = 1; i <= n; i ++ )
    {
        int maxv = 1;
        for (int j = 1; j <= n; j ++ )
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if (a[i] > b[j]) maxv = max(maxv, f[i - 1][j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);
    printf("%d\n", res);

    return 0;
}
