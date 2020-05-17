//金明的预算方案
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

const int maxn = 32010,maxm = 70;
using namespace std;
int n,m,v,p,q,f[maxn];
pair<int,int> a[maxm];
vector<pair<int,int> > G[maxm];
int main(void)
{
    cin >> m >> n;
    for(int i = 1; i <= n;i++)
    {
        scanf("%d%d%d",&v,&p,&q);
        p *= v;
        if(q)G[q].push_back({v,p});
        else a[i] = {v,p};
    }
    
    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= 0; j--)
        {
            if (!a[i].first) continue;
            for (int k = 0; k < 1 << G[i].size(); k++)//神奇的二进制枚举
            {
                int v = a[i].first, w = a[i].second;
                for (int u = 0; u < G[i].size(); u++)
                    if (k >> u & 1)
                    {
                        v += G[i][u].first;
                        w += G[i][u].second;
                    }
                if (j >= v) f[j] = max(f[j], f[j - v] + w);
            }
        }
 
    printf("%d\n", f[m]);
    return 0;
}