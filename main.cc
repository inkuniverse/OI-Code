#include<bits/stdc++.h>
using namespace std;

// 线性基 (p)
int p[1000010], n;
int calcmax()
{
    sort(p + 1, p + n + 1, greater<int>());
    int v = 0;
    for(int i = 1; i <= n; i++)
        v = max(v, v ^ p[i]);
    return v;
}

int calckth(int k) // k 小
{
    sort(p + 1, p + n + 1, greater<int>());
    k += 1; // 否则会算入0
    int v = 0;
    for(int i = 1; i <= n; i++)
    {
        int v1 = v ^ p[i];
        if(v > v1) swap(v, v1);
        if(k > 1 << (n - i))
            v = v1, k -= 1 << (n - i);
    }
    return v;
}

int add(int x)
{
    for(int i = n; i; --i)
        x = min(x, x ^ p[i]);
    if(x)
    {
        p[++n] = x;
        sort(p + 1, p + n + 1);
    }
}