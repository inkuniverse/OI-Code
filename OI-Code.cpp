#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 5050;
int n, m, cnt;
vector<int> G[maxn];
int a[maxn];
void dfs(int root, int fa,int iu,int iv)//iu,iv为被删的边
{
    if(cnt == n)return;
    a[cnt++] = root;
    if(cnt == n)return;
    sort(G[root].begin(), G[root].end());
    for (auto i : G[root])
        if (i != fa)
        {
            dfs(i,root,iu,iv);
        }
};
int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u); //无向图
    }
    if (m == n - 1)
    {
        dfs(1,-1,-1,-1);
        for(int i = 0;i < n;i++)
        {
            printf("%d ",a[i]);
        }
        cnt = 0;
    }
}