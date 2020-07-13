#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define inf 0x7fffffff
int fx[4] = {-1, 0, 1, 0}; // x偏移量
int fy[4] = {0, -1, 0, 1}; // y偏移量
int f[110][110]; // 存储每个点的最优解
int mp[110][110]; // 存储初始棋盘
int m, n, ans = inf;
void dfs(int x, int y, int sum, bool frog)
{
    if(x < 1 || y < 1 || x > m || y > m) return; // 超出边界
    if(sum >= f[x][y]) return; // 不符合最优解
    	// 以上两种情况剪枝
    f[x][y] = sum;
    if(x==m && y==m) // 终点，坐标为(m, m)
    {
        if(sum < ans) ans = sum; // 更新最优解
        return;
    }
    for(int i = 0; i < 4; ++i)
    {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if(mp[xx][yy]) // 若下一格有色
        {
            if(mp[xx][yy] == mp[x][y]) // 若颜色相同
                 dfs(xx, yy, sum, false); // 则不花钱
            else dfs(xx, yy, sum+1, false); // 否则花费+1
        }   else // 否则（若下一格无色）
        if(!frog) // （且）没有用过魔法
        {
            mp[xx][yy] = mp[x][y];
            dfs(xx, yy, sum+2, true); // 使用魔法
            mp[xx][yy] = 0; // 回溯
        }
    }
}
int main()
{
    memset(f, 0x7f, sizeof(f));
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; ++i)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        mp[x][y] = c + 1;
        // 1红色 2黄色 0无色（未赋值，其初值为0）
    }
    dfs(1, 1, 0, false);
    printf("%d", ans==inf ? -1 : ans);
    return 0;
}
