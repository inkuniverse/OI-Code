#include<bits/stdc++.h>
using namespace std;
class Solution {
    int str[256];
    vector<int> G[int(1e5+10)];
    int fa[int(1e5+10)];
    vector<int> ans;
    int aa[int(1e5+10)][256];
    string label;
public:
    int count(int u,char color)
    {
        if(aa[u][color])return aa[u][color];
        int ans = (label[u] == color);
        for(auto v : G[u])
            if(v != fa)
                ans += count(v,color);
        return aa[u][color] = ans;
    }
    void dfs(int u)
    {
        for(auto v : G[u])
            if(v != fa[u])
                fa[v] = u,dfs(v);
    }
    vector<int> countSubTrees(int n, vector<vector<int> >& edges, string labels) {
        for(auto i : edges)
            G[i[0]].push_back(i[1]),G[i[1]].push_back(i[0]);
        label = labels;
        fa[0] = -1;
        dfs(0);
        for(int i = 0;i < n;i++)
            ans.push_back(count(i,label[i]));
        return ans;
    }
};
int main(){}
