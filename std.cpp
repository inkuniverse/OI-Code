#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define inf 0x7fffffff
int fx[4] = {-1, 0, 1, 0}; // xƫ����
int fy[4] = {0, -1, 0, 1}; // yƫ����
int f[110][110]; // �洢ÿ��������Ž�
int mp[110][110]; // �洢��ʼ����
int m, n, ans = inf;
void dfs(int x, int y, int sum, bool frog)
{
    if(x < 1 || y < 1 || x > m || y > m) return; // �����߽�
    if(sum >= f[x][y]) return; // ���������Ž�
    	// �������������֦
    f[x][y] = sum;
    if(x==m && y==m) // �յ㣬����Ϊ(m, m)
    {
        if(sum < ans) ans = sum; // �������Ž�
        return;
    }
    for(int i = 0; i < 4; ++i)
    {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if(mp[xx][yy]) // ����һ����ɫ
        {
            if(mp[xx][yy] == mp[x][y]) // ����ɫ��ͬ
                 dfs(xx, yy, sum, false); // �򲻻�Ǯ
            else dfs(xx, yy, sum+1, false); // ���򻨷�+1
        }   else // ��������һ����ɫ��
        if(!frog) // ���ң�û���ù�ħ��
        {
            mp[xx][yy] = mp[x][y];
            dfs(xx, yy, sum+2, true); // ʹ��ħ��
            mp[xx][yy] = 0; // ����
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
        // 1��ɫ 2��ɫ 0��ɫ��δ��ֵ�����ֵΪ0��
    }
    dfs(1, 1, 0, false);
    printf("%d", ans==inf ? -1 : ans);
    return 0;
}
