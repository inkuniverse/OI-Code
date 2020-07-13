#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n,a[maxn];
void qq(int l,int r)
{
	int i = l,j = r,m = i+j>>1;
	do
	{
		while(a[i] < m)i++;while(a[j] > m)j--;
		if(i<=j)swap(a[i++],a[j--]);
	} while (i <= j);
	if(i < r)qq(i,r);if(l < j)qq(l,j);
}
int main(void)
{
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	for(int i = 0;i < n;i++)
		printf("%d ",a[i]);
}