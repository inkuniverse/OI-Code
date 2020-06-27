#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6+10;
int a[maxn];
int st[maxn][20], n ,m,l,r;//st[i][j] := min(st[i...i+2^(j-1]);
int lg2[maxn];
void init(void)
{
	for (int i = 1; i <= n; i++)
		st[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = max(st[i][j - 1] , st[i + (1 << j - 1)][j - 1]);
	lg2[1] = 0;
	lg2[2] = 1;
	for(int i = 3;i < maxn;i++)
		lg2[i] = lg2[i/2] + 1;
}
int search(int l, int r)
{
	//int k = log2(r - l + 1);
	int k = lg2[r-l+1];
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main()
{
	scanf("%d%d",&n,&m);
    for(int i = 1 ;i <= n;i++)
        scanf("%d",a+i);
    init();
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",search(l,r));
    }
}