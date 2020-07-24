#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2e5+50,maxm=2100,mod=1e9+7,S=2050;
typedef long long long long;
long long N,a[maxn],b[maxn],mul[maxm<<2],invv[maxm<<2],f[maxm<<1][maxm<<1],ans=0;
inline long long qpow(long long a,long long b){long long res=1;while(b){if(b&1) res=(res*a)%mod;b>>=1;a=(a*a)%mod;}return res;}//ksm
inline long long inv(long long x){return qpow(x,mod-2)%mod;}//求逆元 
inline long long C(long long n,long long m){return mul[n]*invv[n-m]%mod*invv[m]%mod;}//求组合数 
int main()
{
	memset(f,0,sizeof(f));
	scanf("%lld",&N);
	for(long long i=1;i<=N;i++) scanf("%lld%lld",&a[i],&b[i]),f[S-a[i]][S-b[i]]++; 
	mul[0]=1,invv[0]=inv(mul[0]);
	for(long long i=1;i<=8000;i++) mul[i]=mul[i-1]*i%mod,invv[i]=inv(mul[i]);
	for(long long i=1;i<=S*2;i++)//dp 
		for( long long j=1;j<=S*2;j++)
			f[i][j]=(f[i][j]+(f[i-1][j]+f[i][j-1])%mod)%mod;
	for(long long i=1;i<=N;i++)
		//ans=(ans+f[S+a[i]][S+b[i]])%mod;
		//ans=(ans-C(2*a[i]+2*b[i],2*a[i]))%mod;
		//ans=(ans%mod+mod)%mod;//防止ans为负数 
		ans = ((((ans+f[S+a[i]][S+b[i]])%mod)-C(2*a[i]+2*b[i],2*b[i]))%mod + mod)%mod;
	ans=(ans*500000004)%mod;
	printf("%lld\n",ans);
	return 0;
}
