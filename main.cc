#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n, mn;
const int N = 100010, oo = 1e9 + 7;
int delta, root, idx;
struct Node
{
    int s[2], p, size, v;
    void init(int in_v,int in_p)
    {
        v = in_v, p = in_p, size = 1;
    }
}tr[N];

void pushup(int u)
{
    tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
}

void rotate(int x)
{
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x,int k)
{
    while(tr[x].p != k)
    {
        int y = tr[x].p, z = tr[y].p;
        if(z != k)
        {
            if((tr[z].s[1] == y) ^ (tr[y].s[1] == x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k) root = x;
}

int insert(int v)
{
    int u = root, p = 0;
    while(u) p = u, u = tr[u].s[v > tr[u].v];
    u = ++idx;
    if(p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p);
    splay(u, 0);
    return u;
}

int get(int v)
{
    int u = root, res;
    while (u)
    {
        if (tr[u].v >= v) res = u, u = tr[u].s[0];
        else u = tr[u].s[1];
    }
    return res;
}

int kth(int u, int k)
{
    if(k <= tr[tr[u].s[0]].size) return kth(tr[u].s[0], k);
    else if(k == tr[tr[u].s[0]].size + 1) return u;
    else return kth(tr[u].s[1], k - tr[tr[u].s[0]].size - 1);
}

void deleteNode(int L,int R)//删除 (L,R) //注意开区间
{
    splay(L, 0);
    splay(R, L);
    tr[R].s[0] = 0;
    pushup(R), pushup(L);
    // splay(R, 0);
    // splay(L, R);
    // tr[L].s[1] = 0;
    // pushup(L), pushup(R);
}

int main(void)
{
    scanf("%d%d", &n, &mn);
    int tot = 0;
    int L = insert(-oo); insert(+oo);
    for(int i = 1;i <= n;i++)
    {
        char op[2];int s;
        scanf("%s%d", op, &s);
        char c = *op;
        if(c == 'I')
        {
            if(s < mn) continue;
                s -= delta, insert(s), tot++;
        }
        else if(c == 'A')
        {
            delta += s;
        }
        else if(c == 'S')
        {
            delta -= s;
            int R = get(mn - delta);
            deleteNode(L, R);
        }
        else if(c == 'F')
        {
            if (tr[root].size - 2 < s) puts("-1");
            //printf("%d\n", tr[kth(root, s)].v + delta);
            else printf("%d\n", tr[kth(root, tr[root].size - s)].v + delta);
        }
    }
    printf("%d\n", tot - (tr[root].size - 2));
}