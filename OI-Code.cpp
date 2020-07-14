
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e5+10,maxm = 1e6+10;
int n, m;
int head[maxn],cnt,a[maxn];
struct edge
{
	int to, next;
}e[maxm];
struct Initialization
{
	int Impossible,black,white;
	Initialization()
	{
		InputGraph();
		Solver();
	}
	void InputGraph()
	{
		auto add = [&](int a, int b)->void
		{
			e[++cnt].next = head[a];
			e[cnt].to = b;
			head[a] = cnt;
		};
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
	}
	void Solver()
	{
		Impossible = 0; 
		black = white = 0;
		dfs(1, 0);
		if (Impossible)puts("Impossible");
		else cout << min(white,black) << endl;
	}
	void dfs(int root,int color)
	{
		if (Impossible)return;
		if(a[root])
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
}Initializationner;

int main(){}