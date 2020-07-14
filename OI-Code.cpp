
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

const int maxn = 1e5+10,maxm = 1e6+10;
int n, m;
int head[maxn],cnt,a[maxn],vis[maxn];
set<int> s;
struct edge
{
	int to, next;
}e[maxm];

struct Initialization
{
	
}Initializationner;
int Impossible, black, white;
int fa[maxn];

int find(int t)						 //各个连通子图
{									 //各个连通子图
	if (fa[t] == t)return t;		 //各个连通子图
	return fa[t] = find(fa[t]);		 //各个连通子图
}									 //各个连通子图
void Union(int x, int y)			 //各个连通子图
{									 //各个连通子图
	x = find(x), y = find(y);		 //各个连通子图
	fa[x] = y;						 //各个连通子图
}									 //各个连通子图
void dfs(int root, int color)
{
	if (Impossible)return;
	if (a[root])
	{
		Impossible = (a[root] != color);//无解
		return;
	}
	a[root] = color;
	if (color)white++; else black++;
	for (int i = head[root]; i; i = e[i].next)
	{
		int v = e[i].to;
		dfs(v, !color);
	}
}
int main()
{
	auto add = [&](int a, int b)->void
	{
		e[++cnt].next = head[a];
		e[cnt].to = b;
		head[a] = cnt;
	};
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
		Union(u, v);
		vis[u] = vis[v] = 1;
	}

	for (int i = 1; i <= n; i++)if(vis[i] == 1 && fa[i] == i)s.insert(i);
	//Solver();
	Impossible = 0;
	int ans = 0;
	for (auto i : s)
	{
		black = white = 0;
		dfs(i, 0);
		ans += min(white, black);
	}
	if (Impossible)puts("Impossible");
	else cout << ans << endl;
}