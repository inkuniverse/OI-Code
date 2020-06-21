#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1010;
int n,m,dp[maxn];
int main(void)
{
	cin>>n>>m;
	for(int i = 0;i < n;i++)
	{
		int v,w;
		cin>>v>>w;
		for(int j = m;j >= v;j--)dp[j] = max(dp[j],dp[j-v]+w);
	}
	cout<<dp[m];
}