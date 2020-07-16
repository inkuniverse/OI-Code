#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
double a[30][2],lt[30][30],zt[(1<<15)+15][18];
double answer;
int bj[30],i,j;//bg是辅助用于记录的/qw:
void dfs(int y,int now,int x,long double ans)
{
	if(x==n+1&&(answer==0 || answer>ans)) 
	{
		answer=ans;
		return;
	}
	for(int val=1;val<=n;val++)
	{
		if(!bj[val])
		{
			int xb=now+(1<<(val-1));
			if(zt[xb][val]!=0)
				if(zt[xb][val]<=ans+lt[y][val]) 
					continue;
			bj[val]=1;
			zt[xb][val]=ans+lt[y][val];
			dfs(val,xb,x+1,zt[xb][val]);
			bj[val]=0;
		}
	}
}

int main()
{
	cin>>n;
	a[0][0]=0;a[0][1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i][0],&a[i][1]);
		for(j=0;j<i;j++)
			lt[i][j]=lt[j][i]=sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
		//预处理距离
	}
	dfs(0,0,1,0);
	printf("%.2lf",answer);
	return 0;
}
