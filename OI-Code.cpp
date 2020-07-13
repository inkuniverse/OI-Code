#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1010,inf = 1e9+7;
int a[maxn][maxn],n,m,ans = 1e9+7;//1 红 2 黄
int rxz[maxn][maxn];
int fx[4] = {-1, 0, 1, 0}; // x偏移量
int fy[4] = {0, -1, 0, 1}; // y偏移量
void dfs(int x,int y,int sum,bool mag)
{
	if(x <= 0 || x > n || y <= 0 || y > n || sum >= rxz[x][y]) return;
	rxz[x][y] = sum;
	if(x == n && y == n)
	{
		if(sum < ans) ans = sum;
		return;
	}
	for(int i = 0;i < 4;i++) // 4个，否则RE.
	{
		int xx = x + fx[i],yy = y + fy[i];
		if(a[xx][yy])
		{
			if(a[xx][yy] == a[x][y])dfs(xx,yy,sum,0);
			else dfs(xx,yy,sum+1,0);//sum + 1 = 坑点
		}
		else
		if(mag == 0)
			a[xx][yy] = a[x][y],dfs(xx,yy,sum + 2,1),a[xx][yy] = 0;
	}
}
int main(void)
{
	cin>>n>>m;
    memset(rxz, 0x7f, sizeof(rxz));
	for(int i = 0;i < m;i++)
	{
		int b,c,d;
		cin>>b>>c>>d;
		a[b][c] = d+1;
	}
    dfs(1, 1, 0, false);
    printf("%d", ans==inf ? -1 : ans);
	return 0;
}
