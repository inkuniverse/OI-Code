#include<iostream>
using namespace std;const int maxn = 233,maxm = 1010;
long long f[maxn][maxn],sum[maxn][maxn],n,m,K;
char a[maxm],b[maxn];
int main(void)
{
    f[0][0] = 1;cin>>n>>m>>K>>a>>b;
    for(int i=1;i<=n;i++)
      for(int j=m;j>=1;j--)
        for(int k=K;k>=1;k--)
              f[j][k]=(f[j][k]+ (sum[j][k]= a[i-1]==b[j-1]? sum[j-1][k]+f[j-1][k-1] : 0))%1000000007;
            //   f[j][k]=(f[j][k]+ (sum[j][k]= (a[i-1]==b[j-1])? (sum[j-1][k]+f[j-1][k-1]) : 0))%1000000007;
    cout<<f[m][K];
}