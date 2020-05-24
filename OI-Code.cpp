#include<bits/stdc++.h>
using namespace std;
const int maxn = 81;

inline int read() 
{
    int X=0,w=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}

int n,m;
int num[maxn];
__int128 ans,p[maxn],f[maxn][maxn];

__int128 dp(int L,int R)
{
    if(f[L][R]!=-1) return f[L][R];
    if(R-L>=1) f[L][R]=max(num[L]*p[m-R+L]+dp(L+1,R),dp(L,R-1)+num[R]*p[m-R+L]);
    else f[L][R]=num[L]*p[m-R+L];
    return f[L][R];
}

void print(__int128 x)
{
    if(x > 9) print(x/10);
    putchar(x%10+'0');
}

int main()
{
    n = read();m = read();
    p[0]=1;
    for(int i=1;i<=m;i++) p[i]=p[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) num[j] = read();
        memset(f,-1,sizeof(f));
        ans+=dp(1,m);
    }
    print(ans);
    return 0;
}