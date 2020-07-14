#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<string>
#include<algorithm>
using namespace std;
struct edge
{
    int to;
    int next;
}e[200000];
int head[20000];
int cnt,black,white;
void add(int a, int b)
{
    cnt++;
    e[cnt].to = b;
    e[cnt].next = head[a];
    head[a] = cnt;
}
bool used[20000];
int col[20000];
bool dfs(int node, int color)
{
    if (used[node])return (col[node] == color);
    used[node] = true;
    col[node] = color;
    if (color) white++; else black++;
    for (int i = head[node]; i; i = e[i].next)
    {
        if(!dfs(e[i].to, 1 - color))return 0;
    }
    return 1;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b;
    while (m--)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (used[i])continue;
        black = white = 0;
        if (!dfs(i, 0))
        {
            printf("Impossible");
            return 0;
        }
        ans += min(black, white);
    }
    printf("%d", ans);
    return 0;
}