#include <algorithm>
using namespace std;
int main(void)
{
	log[1] = 0;
	for(int i = 2; i <= n; i++)
		log[i] = log[i>>1] + 1;
	for(int i = 1; i <= n; i++)
		f[0][i] = a[i];
	for(int j = 1; j < 17; j++)
		for(int i = 1;i <= n;i++)
		f[j][i] = min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
	while(m--)
	{
		scanf("%d%d",&l,&r);
		int i = l,s = 1e9;
		for(int j = 16; j > -1; j--)
			if(r-l+1 & 1<<j)
			{
				s = min(s,f[j][i]);
				i += 1<<j;
			}
		printf("%d\n",s);
	}
}
