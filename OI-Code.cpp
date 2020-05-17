#define _CRT_SECURE_NO_WARNINGS // 谔谔
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxm = 110,inf = 1e9+7;


//先考虑dp.
int stones[maxm], w[maxm*maxm],f[maxm * maxm];//[maxm * maxm]:小小优化，石头之间隔>100没有意义，缩短！

int S, T, m;

int main(void)
{
    scanf("%*d%d%d%d", &S, &T, &m);
    for (int i = 0; i < m; i++)scanf("%d", stones + i);
    if (S == T)
    {
        int res = 0;
        for (int i = 0; i < m; i++)
            if (stones[i] % S == 0)res++;
        printf("%d", res); 
        return 0;
    }
    sort(stones, stones + m);
    int last = 0, k = 0;

    //构造图
    for (int i = 0; i < m; i++)
    {
        //stones[i] - last = 100 => last = stones[i] - 100;
        if(stones[i] - last > 100)last = stones[i] - 100;
        for (int j = 0; j < stones[i] - last; j++)w[++k] = 0;
        w[k] = 1;
        last = stones[i];
    }
    //开始dp
    for (int i = 1; i <= k + 10; i++)
    {
        f[i] = inf;
        for (int j = S; j <= T; j++)
            if (i - j >= 0)
                f[i] = min(f[i], f[i - j] + w[i]);
    }

    int res = inf;
    for (int i = k; i <= k + 10; i++) res = min(res, f[i]);
    printf("%d\n", res);
	return 0;
}