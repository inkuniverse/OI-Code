#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 110,maxm=11,inf=1e9+7;
int n,m;
int a[maxn],f[maxn][maxn][maxm],g[maxn][maxn][maxm];

//int sum(int l,int r)
//{
//	return ((a[r]-a[l-1])%10+10)%10;
//}
#define sum(l,r) (((a[r]-a[l-1])%10+10)%10)


int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",a + i);a[i+n] = a[i];
	}
	for(int i = 1;i <= n*2;i++)a[i] += a[i-1];//前缀和板子
	for(int i = 1;i <= m;i++)
		for(int len = 1;len <= n;len++)
			for(int l = 1;l <= n;l++)
			{
				int r = l+len-1;//区间长度板子
				if(i == 1)f[l][r][i] = g[l][r][i] = sum(l,r);
				else
				{
					f[l][r][i] = -inf;
					g[l][r][i] = -f[l][r][i];
					for(int k = l+i-1;k <= r;k++)//区间长度板子
					{
						int t = sum(k,r);
						f[l][r][i] = max(f[l][r][i],f[l][k-1][i-1]*t);
						g[l][r][i] = min(g[l][r][i],g[l][k-1][i-1]*t);
					}
				}
			}
	//min_element
	int minv = inf,maxv = -inf;
	for(int i = 1;i <= n;i++)
	{
		minv = min(minv,g[i][i+n-1][m]);
		maxv = max(maxv,f[i][i+n-1][m]);
	}
	cout<<minv<<endl<<maxv<<endl;
	return 0;
}
