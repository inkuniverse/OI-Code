#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 5010;
int n;
struct Int
{
    int len, s[MAXN];
    Int()
    {
        len = 1;
        memset(s, 0, sizeof(s));
    }
    Int(int num) { *this = num; }
    Int operator=(const int &num) //开始重载等号,用来赋值
    {
        char a[MAXN];
        sprintf(a, "%d", num); //将整数转成Int型
        len = strlen(a);
        for (int i = len - 1; i >= 0; --i)
            s[i] = a[len - i - 1] - '0';
        return *this;
    }
    Int operator+(const Int &a) //原理与高精加法一样
    {
        Int c;
        c.len = max(len, a.len) + 1;
        for (int i = 0, x = 0; i < c.len; ++i)
        {
            c.s[i] = s[i] + a.s[i] + x;
            x = c.s[i] / 10;
            c.s[i] = c.s[i] % 10;
        }
        if (c.s[c.len - 1] == 0)
            --c.len;
        return c;
    }
};
Int f[MAXN];
ostream &operator<<(ostream &out, const Int &x)
{
    for (int i = x.len - 1; i >= 0; --i)
        cout << x.s[i];
    return out;
}
int main(void)
{
    f[1] = 1;
    f[2] = 2;
    cin >> n;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    cout << f[n];
}
