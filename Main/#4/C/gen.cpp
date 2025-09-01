#include <bits/stdc++.h>
#define int long long
using namespace std;
int tc,m1,m2;
int rdi(int x)
{
	return (1ll*rand()%(1<<20)*(1<<20)+rand()%(1<<20))%x;
}
double rdf()
{
	return (double)1.0*rdi((int)1e10+1)/1e10;
}
bool rdb(double p)
{
	if(rdf()<p) return true;
	return false;
}
bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}
const int N=1e6+12;
bool ins[N],outs[N];
signed main()
{
	srand(time(0));
	while(cin>>tc>>m1>>m2)
	{
		memset(ins,0,sizeof ins);
		memset(outs,0,sizeof outs);
		stringstream ss;
		ss<<tc;
		string s;
		ss>>s;
		fclose(stdout);
		freopen((s+".in").c_str(),"w",stdout);
		int n=900000+rdi(100000),k;
		double p;
		switch(m2)
		{
			case 3: {p=0.5;break;}
			case 2: {p=0;break;}
			case 1: {p=1;break;}
			default: {p=rdf();break;}
		}
		switch(m1)
		{
			case 1:
			{
				k=rdi(1000000000)+1;
				while(__gcd(n,k)!=1) k=rdi(1000000000)+1;
				break;
			}
			case 2:
			{
				while(prime(n)) n=900000+rdi(100000);
				k=rdi(1000000000)+1;
				while(k%n==0||__gcd(n,k)==1) k++;
				while(k>1000000000) k-=n;
				break;
			}
			case 3:
			{
				k=n+n*rdi(1000000000/n);
				break;
			}
		}
		printf("%lld %lld\n",n,k);
		for(int i=0;i<=n-1;i++)
			outs[i]=rdb(p);
		for(int i=0;i<=n-1;i++)
			ins[i]^=outs[i];
		for(int i=0;i<=n-1;i++)
			ins[(i+k)%n]^=outs[i];
		for(int i=n-1;i>=0;i--)
			printf("%d",ins[i]);
		puts("");
		fclose(stdout);
		freopen((s+".out").c_str(),"w",stdout);
		for(int i=n-1;i>=0;i--)
			printf("%d",outs[i]);
		puts("");
	}
	return 0;
}
