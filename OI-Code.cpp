/*
* by 墨宇
* https://ac.nowcoder.com/acm/contest/294/A
* 算法：贪心
*/
#include<iostream>
using namespace std;
int n,a[100001],f[100001],ans;//a[]指原始下陷值，f[]指当前剩多少下陷值
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i];//先一个一个填
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=a[i-1]) f[i]-=a[i-1];//将d(i)的一些操作在d(i-1)的操作里一起完成，偷点懒
        else f[i]=0; //可以完全填平
    }
    for(int i=1;i<=n;i++)
    {
        ans+=f[i];
    }
    cout<<ans;
    return 0;
}