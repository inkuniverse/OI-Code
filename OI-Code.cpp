#include <bits/stdc++.h>
#define N 100005
#define M 1000005
using namespace std;

int n, m, v[N], minv[N], maxv[N];
int sa[N], ans;
queue <int> q;

struct GRAPH 
{//图
	int head[N], to[M], nxt[M], cnt = 1;//前向星
	bool toab[N];//能被到达or能到达

	void addedge(int u, int v) 
	{
		to[cnt] = v;
		nxt[cnt] = head[u];
		head[u] = cnt++;
	}

	void bfs(int s) 
	{
		toab[s] = 1; q.push(s);
		while(q.size()) 
		{
			int p = q.front(); q.pop();
			for(int i = head[p];i;i = nxt[i])
				if(!toab[to[i]])
					toab[to[i]] = 1, q.push(to[i]);
		}
	}

	void mark(int s, int* a, int v) 
	{
		a[s] = v; q.push(s);
		while(q.size()) 
		{
			int p = q.front(); q.pop();
			for(int i = head[p];i;i = nxt[i])
				if(!a[to[i]])//题面保证v>=1就不必初始化成其他值
					a[to[i]] = v, q.push(to[i]);
		}
	}
} mp, fmp;//图和反图

struct Operator
{//点排序规则
	bool operator() (int a, int b) const 
	{
		return v[a] < v[b];
	}
};

int main() 
{
	scanf("%d%d", &n, &m);
	int a, b, op;
	for(int i = 1;i <= n;i++)	
		scanf("%d", v + i);
	while(m--) 
	{
		scanf("%d%d%d", &a, &b, &op);
		mp.addedge(a, b);
		fmp.addedge(b, a);
		if(op == 2) 
		{//存图,存双图就是这里搞错了
			mp.addedge(b, a);
			fmp.addedge(a, b);
		}
	}
	mp.bfs(1); fmp.bfs(n);//能被到达or能到达 执行判断
	for(int i = 1;i <= n;i++) sa[i] = i;
	sort(sa + 1, sa + n + 1, Operator());
	for(int i = 1;i <= n;i++)//标记minv
		if(!minv[sa[i]] && mp.toab[sa[i]])//能被起点到达且没被标记
			mp.mark(sa[i], minv, v[sa[i]]);
	for(int i = n;i;i--)//标记maxv
		if(!maxv[sa[i]] && fmp.toab[sa[i]])//能到达终点且没被标记
			fmp.mark(sa[i], maxv, v[sa[i]]);
	for(int i = 1;i <= n;i++)//更新答案
		if(mp.toab[i] && fmp.toab[i])//存在合法路径
			ans = max(ans, maxv[i] - minv[i]);//尝试更新答案
	printf("%d", ans);
	return 0;
}