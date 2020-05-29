#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn = 110;
int n,a[maxn];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	printf("%d\n", n = unique(a, a + n) - a);
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
}
