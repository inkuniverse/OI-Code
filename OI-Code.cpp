#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n,m,sum;
typedef pair<int,int> P;
vector<P> G[100010];

namespace st1
{
	bool check(int m)
	{
		int m;

	}
	void main()
	{
		int l = 1,r = sum + 1;
		while(l < r)
		{
			int m = l+r+1 >> 1;
			if(check(m)) l = m;
			else r = m-1;
		}
		cout<<l;
	}
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		sum += w;
	}
    return 0;
}
