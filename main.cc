#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 11, M = 110;

int f[N][N][M];

inline int mod(const int &a,const int &b){return (a % b + b) % b;}

int a, b, n;

void init()
{
    memset(f, 0, sizeof f);
    for(int i = 0;i <= 9; i++) f[1][i][i % n]++;

    for(int i = 2; i < N; i++)
        for(int j = 0; j <= 9; j++)
            for(int l = 0; l < n; l++)
                for(int k = 0; k <= 9; k++)
                    f[i][j][l] += f[i - 1][k][mod(l - j, n)];
}

int dp(int n)
{
    if(!n) return 1;

    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10; // 把 n 的每一位抠出来

    int res = 0, last = 0;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for(int j = 0; j < x; j++) res += f[i + 1][j][mod(-last, ::n)];

        last += x;
        if (!i && last % ::n == 0) res++;
    }
    return res;
}

int main(void)
{
    int l, r;
    while(cin >> l >> r)
    {
        init();
        cout << dp(r) - dp(l - 1);
    }
}