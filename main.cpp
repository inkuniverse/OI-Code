#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 40
#define p 100000000
#define ll long long
struct LINT
{
    ll x[M];
    int len;
    LINT()
    {
        memset(x, 0, sizeof x);
        len = 0;
    }
    LINT(const int &x) { *this = x; }
    inline void operator=(const int &x)
    {
        LINT res;
        res.len = 1;
        res[0] = x;
        *this = res;
    }
    inline ll &operator[](const int &cur) { return x[cur]; }
    inline const ll &operator[](const int &cur) const { return x[cur]; }
    LINT operator+(const LINT &a) const
    {
        LINT res;
        res.len = max(len, a.len) + 1;
        for (int i = 0; i < res.len; i++)
        {
            res[i] += x[i] + a[i];
            if (res[i] >= p)
                res[i + 1]++, res[i] -= p;
        }
        while (res.len > 1 && res[res.len - 1] == 0)
            res.len--;
        return res;
    }
    inline void operator+=(const LINT &a) { *this = *this + a; } // ------------------------------------------------------------------------
    LINT operator-(const LINT &a) const
    {
        LINT res;
        res.len = max(len, a.len) + 1;
        for (int i = 0; i < res.len; i++)
        {
            res[i] += x[i] + a[i];
            if (res[i] < 0)
                res[i] += p, res[i + 1]--;
        }
        while (res.len > 1 && res[res.len - 1] == 0)
            res.len--;
        return res;
    }
    inline void operator-=(const LINT &a) { *this = *this - a; }
    LINT operator*(const int &a) const
    {
        LINT res;
        res.len = len + 1;
        for (int i = 0; i < len; i++)
        {
            res[i] += x[i] * a;
            if (res[i] > p)
                res[i + 1] = res[i] / p, res[i] %= p;
        }
        while (res.len > 1 && res[res.len - 1] == 0)
            res.len--;
        return res;
    }
    inline void operator*=(const int &a) { *this = *this * a; }
    LINT operator/(const int &a) const
    {
        LINT res;
        res.len = len;
        ll tmp = 0;
        for (int i = len - 1; ~i; i--)
        {
            tmp *= p;
            res[i] += (x[i] + tmp) / a;
            tmp = (x[i] + tmp) % a;
        }
        while (res.len > 1 && res[res.len - 1] == 0)
            res.len--;
        return res;
    }
    inline void operator/=(const int &a) { *this = *this / a; } // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    inline bool operator<(const LINT &a) const
    {
        if (len != a.len)
            return len < a.len;
        for (int i = len - 1; ~i; i--)
            if (x[i] != a[i])
                return x[i] < a[i];
        return false;
    }
    inline bool operator==(const LINT &a) const { return !(*this < a) && !(a < *this); }
    inline bool operator<=(const LINT &a) const { return *this == a || *this < a; }
    inline bool operator>(const LINT &a) const { return a < *this; }
    inline bool operator>=(const LINT &a) const { return a == *this || a < *this; } // Func
    inline void print()
    {
        int i;
        for (i = len - 1; ~i; i--)
            if (x[i] || i == 0)
            {
                printf("%lld", x[i]);
                break;
            }
        for (i = i - 1; ~i; i--)
            printf("%08lld", x[i]);
    }
};
int main() {}