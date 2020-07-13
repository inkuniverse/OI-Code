#include <iostream>
using namespace std;
const int maxn = 11;
int dp[maxn][maxn];
int f(int n,int m)//n球m
{
	if(dp[n][m])return dp[n][m];
	if(n < m || m <= 0)return 0;
	if(m == n)return 1;
	return dp[n][m] = f(n-1,m-1) +
						f(n-1,m) * m;
}
int omg(int a) //omg = !
{
	if(a == 0)return 1;
	return a * omg(a-1);
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	cout<<f(n,m) * omg(m);
}
