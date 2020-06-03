#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define x first
#define y second

using namespace std;
const int N = 100010;

pair<int, int> w[N];
int n,f[N],g[N],h[N];
/*
f[i] = A[1] + ... + A[i]
g[i] = max(S[1], S[2], ..., S[i])
h[i] = max(A[i] + 2S[i], A[i + 1] + 2S[i + 1], ..., A[n] + 2S[n])
*/

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i].y);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i].x);
    sort(w + 1, w + n + 1);
    reverse(w + 1, w + n + 1);

    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + w[i].x;
    for (int i = 1; i <= n; i++) g[i] = max(g[i - 1], w[i].y);
    for (int i = n; i; i--) h[i] = max(h[i + 1], w[i].x + 2 * w[i].y);

    for (int x = 1; x <= n; x++) printf("%d\n", max(f[x - 1] + h[x], f[x] + 2 * g[x]));

    return 0;
}
