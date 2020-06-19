#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
const int maxn = 510;
int n,a[maxn],b[maxn];
const string stat[2] = {"Yes","No"};
int main(void)
{
	srand(time(0));
	int T;
	cin>>T;
	while(T--)
	{
		//cin>>n;
		//for(int i = 0;i < n;i++)
		//	cin>>a[i];
		//for(int i = 0;i < n;i++)
		//	cin>>b[i];
		cout<<stat[rand()%2];
	}
}