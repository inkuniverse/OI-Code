//比例简化
#include <cstdio>
#include <iostream>
// 现给出支持人数A，反对人数 B ，以及一个上限 L ，请你将 A 比 B 化简为 A ’比 B ’，
// 要求在 A ’和 B ’均不大于 L 且 A ’和 B ’互质（两个整数的最大公约数是 1 ）的前提下，
// A ’ /B ’ ≥ A/B 且 A ’ /B ’ - A/B 的值尽可能小。

using namespace std;
int a, b, c, aa, bb;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main(void)
{
    cin >> a >> b >> c;
    for (int i = 0; i <= c; i++)
        for (int j = 1; j <= c; j++)
            if (gcd(i, j) == 1 && ((double)i / j) >= ((double)a / b) && ((aa == 0 && bb == 0) || ((((double)i/j) - ((double)a/b)) < (((double)aa/bb) - ((double)a/b)))))
                aa = i,bb = j;
    cout<<aa<<" "<<bb;
}