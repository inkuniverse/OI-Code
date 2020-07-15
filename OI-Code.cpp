#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 100010;
int a,n,cnt,m,sum;
int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n;i++) 
	{
		scanf("%d",&a);
		if(sum + a > m){sum = a;cnt++;}
		else {sum += a;}
	}
	cout<<cnt+1;//最后还有一组
	return 0;
}