#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 10010, maxm = (maxn+1e5) * 2, inf = 1e8;
int n,m,S,T,sc,tc;
int h[maxn],e[maxm],ne[maxm],f[maxm],idx;
int cur[maxn],d[maxn];
queue<int> q;
void add(int u,int v,int w)
{
    e[idx] = v; f[idx] = w;ne[idx] = h[u];h[u] = idx++;
    e[idx] = u; f[idx] = 0;ne[idx] = h[v];h[v] = idx++;
}
bool bfs()
{
    q = queue<int>();
    memset(d, -1, sizeof d);
    q.push(S);d[S] = 0;cur[S] = h[S];
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int i = h[u];~i;i=ne[i])
        {
            int v = e[i];
            if(d[v] == -1 && f[i])
            {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if(v == T)return true;
                q.push(v);
            }
        }
    }
    return false;
}

int find(int u,int limit)
{
    if(u == T) return limit;
    int flow = 0;
    for(int i = cur[u];~i && flow < limit;i = ne[i])
    {
        cur[u] = i;
        int v = e[i];
        if(d[v] == d[u] + 1 && f[i])
        {
            int t = find(v,min(f[i],limit - flow));
            if(!t) d[v] = -1;
            f[i] -= t;f[i^1] += t;flow += t;
        }
    }
    return flow;
}

int dinic()
{
    int r = 0,flow;
    while(bfs())while(flow = find(S,inf))r += flow;
    return r;
}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d%d%d",&n,&m,&sc,&tc);
    S = 0;T = n+1;
    while(sc--)
    {
        int t;
        scanf("%d",&t);
        add(S,t,inf);
    }
    while(tc--)
    {
        int t;
        scanf("%d",&t);
        add(t,T,inf);
    }
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    printf("%d\n",dinic());
}
