
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 10000 + 10, maxm = 2 * 100000 + 10, inf = 1e8;
int n,m,S,T;
int h[maxn],e[maxm],ne[maxm],idx,f[maxm];
queue<int> q;
int d[maxn],cur[maxn];
void add(int u,int v,int w)
{
	e[idx] = v, f[idx] = w, ne[idx] = h[u], h[u] = idx++;
	e[idx] = u, f[idx] = 0, ne[idx] = h[v], h[v] = idx++;
}
bool bfs()
{
	q = queue<int>();
	memset(d,-1,sizeof d);
	q.push(S);d[S] = 0;cur[S] = h[S];
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(int i = h[u];~i;i = ne[i])
		{
			int v = e[i];
			if(d[v] == -1 && f[i])
			{
				d[v] = d[u] + 1;
				cur[v] = h[v];
				if(v == T) return true;
				q.push(v);
			}
		}
	}
	return false;
}
int find(int u,int limit)
{
	if(u == T)return limit;
	int flow = 0;
	for(int i = cur[u]; ~i && flow < limit;i = ne[i])
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
	while(bfs()) while(flow = find(S,inf))r += flow;
	return r;
}
int main(void)
{
	memset(h,-1,sizeof h);
	scanf("%d%d%d%d", &n, &m, &S, &T);
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	printf("%d\n",dinic());
}
