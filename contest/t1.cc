#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 55;
int T,n,m,a[maxn][maxn];
const string ava[2] = {"Ashish\n","Vivek\n"};
int main(void)
{
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof a);
        cin>>n>>m;
        int cnt = n*m;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                scanf("%d",&a[i][j]);

        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(a[i][j] == 1)
                {
                    for(int k = 0;k < m;k++)
                        a[i][k] = 1;
                    for(int k = 0;k < n;k++)
                        a[k][j] = 1;
                }

        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cnt -= a[i][j];
        while(cnt > 0)
        {
            //Ashish
            int maxA = -100,x,y,A;
            for(int i = 0;i < n;i++)
                for(int j = 0;j < m;j++)
                {
                    if(a[i][j] == 1)continue;
                    A = 0;
                    for(int k = 0;k < m;k++)
                        A += !a[i][k];
                    for(int k = 0;k < n;k++)
                        A += !a[k][j];
                    if(A>maxA)
                    {
                        x = i,y = j;
                        maxA = A;
                    }
                }
            for(int k = 0;k < m;k++)
                a[x][k] = 1;
            for(int k = 0;k < n;k++)
                a[k][y] = 1;
            cnt -= maxA-1;
            if(cnt <= 0){cout<<ava[0];break;}

            //Vivek
            int maxB = -100,B;
            for(int i = 0;i < n;i++)
                for(int j = 0;j < m;j++)
                {
                    if(a[i][j] == 1)continue;
                    B = 0;
                    for(int k = 0;k < m;k++)
                        B += !a[i][k];
                    for(int k = 0;k < n;k++)
                        B += !a[k][j];
                    if(B>maxB)
                    {
                        x = i,y = j;
                        maxB = B;
                    }
                }
            for(int k = 0;k < m;k++)
                a[x][k] = 1;
            for(int k = 0;k < n;k++)
                a[k][y] = 1;
            if(cnt <= 0){cout<<ava[1];break;}
        }
    }
    return 0;
}