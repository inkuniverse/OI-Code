#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

const int N = 100010, mod = 10007;

stack<char> sOper;
stack<vector<int>> sNumber;

void eval()
{
    auto c = sOper.top(); sOper.pop();
    auto a = sNumber.top(); sNumber.pop();
    auto b = sNumber.top(); sNumber.pop();

    if (c == '+') sNumber.push({ a[0] * b[0] % mod, (a[0] * b[1] + a[1] * b[0] + a[1] * b[1]) % mod });
    else sNumber.push({(a[0] * b[0] + a[0] * b[1] + a[1] * b[0]) % mod, a[1] * b[1] % mod});
}

int main()
{
    int n;
    string expr;
    cin >> n >> expr;

    map<char, int> pr;
    pr['('] = 0, pr['+'] = 1, pr['*'] = 2;//优先级

    sNumber.push({ 1, 1 });
    for (auto c : expr)
    {
        if (c == '(') sOper.push(c);
        else if (c == '+' || c == '*')
        {
            while (!sOper.empty() && pr[sOper.top()] >= pr[c]) eval();
            sNumber.push({ 1, 1 });
            sOper.push(c);
        }
        else
        {
            while (sOper.top() != '(') eval();
            sOper.pop();
        }
    }

    while (!sOper.empty()) eval();//继续操作直到空
    cout << sNumber.top()[0] << endl;

    return 0;
}
