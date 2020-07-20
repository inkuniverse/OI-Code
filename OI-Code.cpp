#include<iostream>
using namespace std;
vector<int> G[N];
int siz[N],son[N],dfn[N],cnt,top[N],fa[N],d[N];
void dfs1(int x)
{
	siz[x] = 1;
	for(auto y:G[x])
		if(y!=fa[x])fa[y]=x,d[y] = d[x] + 1,dfs1(y,x),siz[x] += siz[y];
	int mx = 0;
	for(auto y:G[x])
		if(y!=fa[x]) if(mx<siz[y])mx=siz[y],son[x] = y;
}
void dfs2(int x,int pa){
	dfn[x] = ++cnt;
	if(son[x])
	{
		top[son[x]] = top[x];
		dfs2(son[x],x);
	}
	for(auto y:G[x])if(y!=fa[x] && y!=son[x])
	{
		top[y] = y;
		dfs2(y,x);
	}
}
int lca(int x,int y)
{
	while(top(x) != top(y)){
		if(d[top[x]] < d[top[y]])swap(x,y);
		x = fa[top[x]];
	}
	if(d[x]<d[y])return x;
	else return y;
}
int main()
{
	inp();
	fa[1] = -1;
	dfs1(1);
	top[1] = 1;
	dfs2(1);
}
