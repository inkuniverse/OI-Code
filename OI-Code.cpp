#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 5005;
using namespace std;

int cnt;
int head[maxn];
struct edge
{
    int u, v, next;
} e[maxn << 1];

void add(int u, int v)
{
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

vector<int> vec[maxn];

int n, m;
int ans[maxn];
int k[maxn];

int x, y;
int dep;
bool vis[maxn];

void dfs(int u, int fa)
{
    if (vis[u])
        return;
    vis[u] = 1;
    k[++dep] = u;
    for (int i = 0; i < vec[u].size(); i++)
    {
        int v = vec[u][i];
        if (v == fa)
            continue;
        if ((v == y && u == x) || (v == x && u == y))
            continue;
        dfs(v, u);
    }
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (k[i] == ans[i])
            continue;
        if (k[i] > ans[i])
            return false;
        else
            return true;
    }
}

void change()
{
    for (int i = 1; i <= n; i++)
        ans[i] = k[i];
}

void dfs2(int u, int fa)
{
    if (vis[u])
        return;
    vis[u] = 1;
    ans[++dep] = u;
    for (int i = 0; i < vec[u].size(); i++)
    {
        int v = vec[u][i];
        if (v == fa)
            continue;
        dfs2(v, u);
    }
}

int main()
{
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
        add(u, v);
        add(v, u);//其实存边，顺手链式前向星
    }
    for (int i = 1; i <= n; i++)
        sort(vec[i].begin(), vec[i].end());
    if (n == m)
    {
        for (int i = 1; i <= cnt; i += 2)//if cnt++ := i=0
        {
            dep = 0;
            x = e[i].u;
            y = e[i].v;
            memset(vis, 0, sizeof(vis));
            dfs(1, -1);
            if (dep < n)
                continue;
            if (ans[1] == 0)
                change();
            else if (check())
                change();
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
    }
    else
    {
        dfs2(1, -1);
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
    }
    return 0;
}