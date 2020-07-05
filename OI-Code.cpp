#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 110;
int f[25100], T, n, a[maxn];
int ans;
int main(void)
{
    scanf("%d", &T);
    while (T--)
    {
        memset(f,0,sizeof f);

        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            f[a[i]] = 2;
        }
        sort(a+1,a+n+1);
        for(int i = 1;i <= a[n];i++)
            if(f[i] > 0) for(int j = 1;j <= n;j++)
                if(i + a[j] <= a[n])f[i+a[j]] = 1; else break;
        
        for(int i = 1;i <= a[n];i++)
            if(f[i] == 2)ans++;
        cout<<ans<<endl;
    }
}