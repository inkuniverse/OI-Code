#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

#define x first
#define y second

typedef pair<double,double> PDD;
const int N = 18, M = 1 << N;
const double eps = 1e-6;//解决浮点误差！

int n,m,path[N][N],f[M],ulowbit[M];
PDD q[N];

int cmp(double x,double y)
{
	if(fabs(x-y)<=eps)return 0;
	if(x<y)return -1;//不用比较eps  => 参见浮点数误差
	return 1;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;i++)scanf("%lf%lf", &(q[i].x),&(q[i].y));
		for(int i = 0;i + 1 < 1<<n;i++)//枚举子集
		{
			for(int j = 0;j < n;j++)
				if(!(i >> j & 1))
				{
					ulowbit[i] = j;
					break;
				}
		}
		memset(path, 0,sizeof path);//切记！必须清零！
		for(int i = 0;i < n;i++)
		{
			path[i][i] = 1 << i;
			for(int j = 0;j < n;j++)
			{
				if(!cmp(q[i].x,q[j].x))continue;
				double x1 = q[i].x,y1 = q[i].y,x2= q[j].x,y2 = q[j].y;
				double b = (y1 * x2 * x2 / x1 / x1 - y2) / (x2 * x2 / x1 - x2);
				double a = (y1 - b * x1) / x1 / x1;
				if (a > 0) continue;
				int state = 0;
				for (int k = 0; k < n; k ++ )
				{
					double x = q[k].x, y = q[k].y;
					if (!cmp(y, a * x * x + b * x)) state += 1 << k;
				}
				 
				path[i][j] = state;
			}
		}
		 
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		 
		for (int i = 0; i + 1 < 1 << n; i ++ )
		{
			int x = ulowbit[i];
			for (int j = 0; j < n; j ++ )
				f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
		}
		 
		printf("%d\n", f[(1 << n) - 1]);
	}
	 
	return 0;
}
