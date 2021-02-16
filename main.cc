#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int T, n;
long long a[N];
int main(void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", a + i);
        long long ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= n; k++)
                    ans = (ans + (((a[i] & a[j]) % (long long)(1000000007)) * (a[j] | a[k])) % (long long)(1000000007)) % (long long)(1000000007);
        
        printf("%lld\n", ans);
    }
}