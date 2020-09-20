#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 500010;

int root[N], p[N];
int find(int x)
{
    if(x == p[x])return x;
    return p[x] = find(p[x]);
}

int n, m, idx;
struct Node
{
    int p, s[2], size, v, id;
    void init(int _v,int _id,int _p)
    {
        p = _p, v = _v, size = 1, id = _id;
    }
}tr[N];

void pushup(int u)
{
    tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
}

void rotate(int x)
{
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x,int k,int b)
{
    while(tr[x].p != k)
    {
        int y = tr[x].p, z = tr[y].p;
        if(z != k)
        {
            if((tr[z].s[1] == y) ^ (tr[y].s[1] == x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k) root[b] = x;
}

void insert(int v,int id,int b)
{
    int u = root[b], p = 0;
    while(u) p = u, u = tr[u].s[tr[u].v < v];
    u = ++idx;
    if(p) tr[p].s[tr[p].v < v] = u;
    tr[u].init(v, id, p);
    splay(u, 0, b);
}

int kth(int k,int b)
{
    int u = root[b];
    while(u)
    {
        if(tr[tr[u].s[0]].size >= k) u = tr[u].s[0];
        else if(tr[tr[u].s[0]].size + 1 == k) return u;
        else k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
    }
    puts("-1");
    return -1;
}

void dfs(int u, int v)
{
    if(tr[u].s[0]) dfs(tr[u].s[0], v);
    if(tr[u].s[1]) dfs(tr[u].s[1], v);
    insert(tr[u].v, tr[u].id, v); 
}

int main(void)
{
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        p[i] = root[i] = i;
        int v;
        scanf("%d", &v);
        tr[i].init(v, i, 0);
    }
    idx = n;
    for(int i = 1;i <= m;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u = find(u), v = find(v);
        if(u != v)
        {
            if(tr[root[u]].size > tr[root[v]].size) swap(u, v);
            dfs(root[u], v);
            p[u] = v;
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(*op == 'B')
        {
            a = find(a), b = find(b);
            if(a != b)
            {
                if(tr[root[a]].size > tr[root[b]].size)swap(a,b);
                dfs(root[a], b);
                p[a] = b;
            }
        }
        else if(*op == 'Q')
        {
            a = find(a);
            if (tr[root[a]].size < b) puts("-1");
            else printf("%d\n", tr[kth(b, a)].id);
        }
    }
}