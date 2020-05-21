//回文日期
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int ts[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, b, e, ans = 0;
int main()
{
    cin >> b >> e;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= ts[i]; j++)
        {
            int A = j % 10, B = j / 10, C = i % 10, D = i / 10;
            int date = A + B * 10 + C * 100 + D * 1000 + D * 10000 + C * 100000 + B * 1000000 + A * 10000000;
            if (date >= b && date <= e)
                ans++;
        }
    }
    cout << ans;
    return 0;
}