//扫雷游戏
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 110;
int n,m;
char a[maxn][maxn];
int cnt[maxn][maxn];
const int dx[8] = {-1,0,1,-1,1,-1,0,1};
const int dy[8] = {-1,-1,-1,0,0,1,1,1};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin>>a[i][j];
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(a[i][j] == '*')
                for(int k = 0;k < 8;k++)
                    cnt[i+dx[k]][j+dy[k]]++;
    for(int i = 1;i <= n;i++,puts(""))
        for(int j = 1;j <= m;j++)
            if(a[i][j] == '?')cout<<cnt[i][j];
            else cout<<a[i][j];
}