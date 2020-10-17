/*
总的来说还是要静下来把规律找到
然后分类讨论
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
    int x, y;
    cin >> x >> y;

    if (abs(x) <= y)  // 在上方
    {
        int n = y;
        cout << (LL)(2 * n - 1) * (2 * n) + x - (-n) << endl;
    }
    else if (abs(y) <= x)  // 在右方
    {
        int n = x;
        cout << (LL)(2 * n) * (2 * n) + n - y << endl;
    }
    else if (abs(x) <= abs(y) + 1 && y < 0)  // 在下方
    {
        int n = abs(y);
        cout << (LL)(2 * n) * (2 * n + 1) + n - x << endl;
    }
    else  // 在左方
    {
        int n = abs(x);
        cout << (LL)(2 * n - 1) * (2 * n - 1) + y - (-n + 1) << endl;
    }

    return 0;
}
