#include<stdio.h>
int dp[1000010], g1[1000010], g2[1000010], cnt;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int v, w, s;
		scanf("%d%d%d", &v, &w, &s);
		for (int k = 1; k <= s; k *= 2)
		{
			s -= k;
			g1[cnt] = v * k;
			g2[cnt++] = w * k;
		}
		if (s > 0)g1[cnt] = v * s, g2[cnt++] = w * s;
	}
    for(int i = 0;i < cnt;i++)
        for(int j = m;j >= g1[i]; j--)
            if(dp[j - g1[i]] + g2[i] > dp[j]) dp[j] = dp[j - g1[i]] + g2[i];
            
	printf("%d", dp[m]);
	return 0;
}