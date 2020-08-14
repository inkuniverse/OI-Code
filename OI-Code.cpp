#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
const int maxn = 10000 * 10 + 10, maxm = 50000 * 10 + 10;
int h[maxn], e[maxm], ne[maxm], f[maxm], idx;
int n,m,S,T,k;
void add(int u,int v,int w)
{
	e[idx] = v, f[idx] = w, ne[idx] = h[u], h[u] = idx++;
	// e[idx] = u, f[idx] = w, ne[idx] = h[v], h[v] = idx++;
}
int main(void)
{
	scanf("%d", &n);	
}