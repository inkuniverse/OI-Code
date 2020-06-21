#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 500010;
int n,a[maxn],f[maxn],g[maxn],s[maxn];
//f[i]表示遍历时间+子树所有居民装好电脑的时间
//g[i]表示遍历时间
vector<int> G[maxn];

void dfs(int u,int fa)
{
	if(u != 1)f[u] = a[u];
	for(auto v:G[u])if(v != fa)dfs(v,u);
	int cnt = 0;
	for(auto v:G[u])if(v != fa)s[cnt++] = v;//保存儿子
	sort(s+1,s+cnt+1,[](int a,int b){return f[a]-g[a] > f[b]-g[b];});
	for(int i = 1;i <= cnt;i++)
	{
		f[u] = max(f[u],f[s[i]]+g[u]+1);
		g[u] += g[s[i]] + 2;//更新g[]
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",a + i);
	for(int i = 1;i < n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,-1);//g[1]+a[1]是特判
	printf("%d",max(f[1],g[1]+a[1]));
	return 0;
}
