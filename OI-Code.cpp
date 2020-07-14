#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 45;
int m,n,f[maxn][maxn][maxn][maxn],g[5],ar[355];
int main(void)
{
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        scanf("%d",ar+i);
    for(int i = 0;i < m;i++)
    {
        int x;cin>> x;
        g[x]++;
    }
    f[0][0][0][0] = ar[1];
    for(int a = 0;a <= g[1];a++)
        for(int b = 0;b <= g[2];b++)
            for(int c = 0;c <= g[3];c++)
                for(int d = 0;d <= g[4];d++)
                {
                    int num = ar[a*1+b*2+c*3+d*4 + 1];
                    if(a!=0)f[a][b][c][d] = max(f[a][b][c][d],f[a-1][b][c][d] + num);
                    if(b!=0)f[a][b][c][d] = max(f[a][b][c][d],f[a][b-1][c][d] + num);
                    if(c!=0)f[a][b][c][d] = max(f[a][b][c][d],f[a][b][c-1][d] + num);
                    if(d!=0)f[a][b][c][d] = max(f[a][b][c][d],f[a][b][c][d-1] + num);
                }
    cout<<f[g[1]][g[2]][g[3]][g[4]];
}
