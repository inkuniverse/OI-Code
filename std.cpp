#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
 
#define x first
#define y second
 
using namespace std;

typedef pair<double, double> PDD;
 
const int N = 18, M = 1 << N;
const double eps = 1e-6;
 
int n, m;
PDD q[N];
int path[N][N];
int f[M];
int ulowbit[M];
 
int cmp(double x, double y)
{
    if (fabs(x - y) <= eps) return 0;
    if (x < y) return -1;
    return 1;
}
 
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++ ) scanf("%lf%lf", &q[i].x, &q[i].y);
         
        for (int i = 0; i + 1 < 1 << n; i ++ )
        {
            for (int j = 0; j < n; j ++ )
                if (!(i >> j & 1))
                {
                    ulowbit[i] = j;
                    break;
                }
        }
         
        memset(path, 0, sizeof path);
         
        for (int i = 0; i < n; i ++ )
        {
            path[i][i] = 1 << i;
            for (int j = 0; j < n; j ++ )
            {
                if (!cmp(q[i].x, q[j].x)) continue;
                double x1 = q[i].x, y1 = q[i].y, x2 = q[j].x, y2 = q[j].y;
                double b = (y1 * x2 * x2 / x1 / x1 - y2) / (x2 * x2 / x1 - x2);
                double a = (y1 - b * x1) / x1 / x1;
                if (a > 0) continue;
                int state = 0;
                for (int k = 0; k < n; k ++ )
                {
                    double x = q[k].x, y = q[k].y;
                    if (!cmp(y, a * x * x + b * x)) state += 1 << k;
                }
                 
                path[i][j] = state;
            }
        }
         
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
         
        for (int i = 0; i + 1 < 1 << n; i ++ )
        {
            int x = ulowbit[i];
            for (int j = 0; j < n; j ++ )
                f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
        }
         
        printf("%d\n", f[(1 << n) - 1]);
    }
     
    return 0;
}
