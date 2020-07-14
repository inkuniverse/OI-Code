#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e4+10;
int f[maxn], n, m, s,t;
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
struct road
{
    int x,y,t;
    bool operator<(road b)
    {
        return t < b.t;
    }
}r[maxn*10];


int main(void)
{
    scanf("%d%d", &n, &m,&s,&t);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        r[i].x = x,r[i].y = y,r[i].t = t;
    }
    sort(r+1,r+m+1);
    for(int i = 1;i <= m;i++)
    {
        int x = find(r[i].x),y = find(r[i].y);
        if(x != y)
        {
            f[x] = y;
            if(find(s) == find(t)){cout<<r[i].t;return 0;}
        }
    }
    cout<<-1;
}