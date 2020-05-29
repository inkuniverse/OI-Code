#include<iostream>
#include<algorithm>
using namespace std;
int a[1010],n;
int main(void)
{
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		int b;cin>>b;
		a[b] = 1;
	}
	cout<<count(a,a+1010,1)<<endl;
	for(int i = 0;i < 1010;i++)
		if(a[i])cout<<i<<' ';
	return 0;
}
