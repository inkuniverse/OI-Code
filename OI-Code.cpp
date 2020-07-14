#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100;
int n,a[maxn],f[maxn],g[maxn];
int main(void)
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d", a + i);
	fill(f+1,f + n + 1,1);
	fill(g+1,g + n + 1,1);

	for(int i = 1;i <= n;i++)
		for(int j = 1;j < i;j++)
			if(a[j] < a[i])f[i] = max(f[i],f[j] + 1);

	for(int i = n;i > 0;i--)
		for(int j = i+1;j <= n;j++)
			if(a[j] < a[i])g[i] = max(g[i],g[j] + 1);
	int ans = 0;
	for(int i = 1;i<=n;i++)ans = max(ans,f[i] + g[i] - 1);
	cout<<n-ans;
}
