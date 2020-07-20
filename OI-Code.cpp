#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
vector<int> G[N];
int siz[N],son[N],dfn[N],cnt,top[N],fa[N],d[N];//begin 线段树
#define P (k<<1)
#define S (P|1)
#define M (i+j>>1)
int a[200005], f[524288];
void build(int i, int j, int k) {
	if (i == j)
		f[k] = a[i];
	else {
		build(i, M, P);
		build(M+1, j, S);
		f[k] = min(f[P],f[S]);
	}
}
int ask(int u, int v, int i, int j, int k) {
	if (u == i && v == j)
		return f[k];
	if (v <= M)
		return ask(u, v, i, M, P);
	if (u > M)
		return ask(u, ,v M+1, j, S);
	return min(ask(u, M, i, M, P), ask(M+1, v, M+1, j, S));
}
int point_update(int i,int j,int k,int v,int p)/*a[p] = v;*/{
	if(i == j)
		f[k] = v;
	else {
		if(M > p)point_update(i,M,P,v,p);
		else point_update(M+1,j,S,v,p);
		f[k] = min(f[P],f[S]);
	}
}//结束 线段树板子 开始 LCT板子
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
		top[son[x]] = top[x],dfs2(son[x],x);
	for(auto y:G[x])if(y!=fa[x] && y!=son[x])top[y] = y,dfs2(y,x);
}
int lca(int x,int y)
{
	while(top(x) != top(y)){
		if(d[top[x]] < d[top[y]])swap(x,y);
		x = fa[top[x]];
	}
	return (d[x] < d[y])?x:y;
}
//结束 lct板子
int main()
{
	inp();
	fa[1] = -1;
	dfs1(1);
	top[1] = 1;
	dfs2(1);
}
