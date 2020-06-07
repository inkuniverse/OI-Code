#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 300010;
int m,s,t;
int f[maxn];
int main(void)
{
	scanf("%d%d%d",&m,&s,&t);
	//闪现
	for(int i = 1;i <= t;i++)
	{
		if(m >= 10)
			f[i] = f[i-1] + 60,m -= 10;
		else
			m += 4,f[i] = f[i-1];
	}
	//跑步
	for(int i = 1;i <= t;i++)
		f[i] = max(f[i],f[i-1] + 17);
	if (f[t] >= s)
	{
		for (int i = 1; i <= t; i++)
			if (f[i] >= s)
			{
				printf("Yes\n%d\n", i);
				break;
			}
	}
	else printf("No\n%d\n", f[t]);
	return 0;
}