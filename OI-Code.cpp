#include <cstdio>
#include <algorithm>
const int maxn = 10010;
int n, a[maxn], k;
int T[maxn],cnt;
void merge_sort(int *A,int x,int y,int *T,int &cnt)
{
	if(y-x>1)
	{
		int m = x+(y-x)/2;
		int p = x,q = m,i = x;
		merge_sort(A,x,m,T,cnt);
		merge_sort(A,m,y,T,cnt);
                //此时左半右半都有序
		while(p<m || q<y)
		{
			if(q >= y || (p<m && A[p]<=A[q])) T[i++] = A[p++];
			else {T[i++] = A[q++];cnt += m - p; }
		}
		for(int i = x;i < y;i++)A[i] = T[i];
	}
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",a+i);
	merge_sort(a,0,n,T,cnt);
	printf("%d",cnt);
}