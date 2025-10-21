#include <bits/stdc++.h>
using namespace std;
long long rds(int x)
{
	long long c=0;
	for(int i=1;i<=x;i++)
		c*=10,c+=rand()%10;
	return c+1;
}
long long rd(long long x)
{
	return rds(18)%x+1;
}
long double rdf()
{
	return (long double)1.0e-18*rds(18);
}
struct S
{
	int x;
	int y;
};
S a[100012];
bool w[100012];
int v[100012];
int c=0;
int b[100012];
bool cmp(S x,S y)
{
	return x.y<y.y;
}
bool adjust(int n)
{
	int tries=10000;
	bool ok=false;
	do
	{
		tries--;
		ok=true;
		for(int i=1;i<=n-1;i++)
			if(b[i]==b[i+1])
			{
				ok=false;
				swap(b[i],b[rd(n)]);
			}
		if(b[1]==b[n])
		{
			ok=false;
			swap(b[n],b[rd(n)]);
		}
	}
	while(!ok&&tries);
	return tries;
}
void arrange(int n)
{
	memset(w,0,sizeof w);
	memset(v,0,sizeof v);
	c=0;
	for(int i=1;i<=n;i++)
	{
		if(!w[b[i]])
		{
			w[b[i]]=true;
			c++;
			v[b[i]]=c;
		}
	}
	for(int i=1;i<=n;i++)
		b[i]=v[b[i]];
}
void output(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<b[i];
		if(i!=n) cout<<" ";
	}
	cout<<endl;
}
void gen(int tp,int cc,int n1,int n2)
{
	int n=n1+rds(n2);
	switch(cc)
	{
		case -1:
		{
			if(n%2) n--;
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<(i-1)%2+1;
				if(i!=n) cout<<" ";
			}
			cout<<endl;
			break;
		}
		case -2:
		{
			if(n%2) n--;
			cout<<n<<endl;
			for(int i=1;i<=n/2;i++)
				cout<<i<<" ";
			for(int i=1;i<=n/2;i++)
			{
				cout<<i;
				if(i!=n) cout<<" ";
			}
			cout<<endl;
			break;
		}
		case -3:
		{
			while(n%5) n--;
			cout<<n<<endl;
			do
			{
				memset(a,0,sizeof a);
				for(int i=1;i<=n;i++)
				{
					a[i].x=(i-1)%(n/5)+1;
					a[i].y=rds(9);
				}
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n;i++)
					b[i]=a[i].x;
			}
			while(!adjust(n));
			arrange(n);
			output(n);
			break;
		}
		default:
		{
			cout<<n<<endl;
			switch(tp)
			{
				case 1:
				{
					do
					{
						for(int i=1;i<=n;i++)
							b[i]=rd(cc);
					}
					while(!adjust(n));
					arrange(n);
					output(n);
					break;
				}
				case 2:
				{
					do
					{
						for(int i=1;i<=n;i++)
							b[i]=cbrtl(rd(1ll*cc*cc*cc)-1)+1;
					}
					while(!adjust(n));
					arrange(n);
					output(n);
					break;
				}
				case 3:
				{
					do
					{
						memset(a,0,sizeof a);
						int m=n;
						int f=0;
						do
						{
							// Cauchy Distribution
							int count=max(m/cc,1);
							int mu=rds(9)-5e8;
							int sigma=rds(8)+5e7;
							int lang=rd(cc);
							m-=count;
							for(int i=1;i<=count;i++)
							{
								f++;
								a[f].x=lang;
								long double value=0;
								do value=mu+sigma*tanl(acosl(-1)*(rdf()-0.5)); while(value<-1e9||value>1e9);
								a[f].y=value;
							}
						}
						while(m);
						sort(a+1,a+n+1,cmp);
						for(int i=1;i<=n;i++)
							b[i]=a[i].x;
					}
					while(!adjust(n));
					arrange(n);
					output(n);
					break;
				}
				default:
				{
					for(int i=1;i<=n;i++)
					{
						cout<<(i-1)%cc+1;
						if(i!=n) cout<<" ";
					}
					break;
				}
			}
			break;
		}
	}
}
int main()
{
	srand(time(0));
	string tc;
	int cc,n1,n2;
	while(cin>>tc>>cc>>n1>>n2)
	{
		tc+=".in";
		freopen(tc.c_str(),"w",stdout);
		cout<<10<<endl;
		if(cc>25)
		{
			for(int i=1;i<=3;i++)
				gen(1,cc,n1,n2);
			for(int i=4;i<=6;i++)
				gen(2,cc,n1,n2);
			for(int i=7;i<=9;i++)
				gen(3,cc,n1,n2);
		}
		else
		{
			for(int i=1;i<=9;i++)
				gen(1,cc,n1,n2);
		}
		gen(0,cc,n1,n2);
	}
	return 0;
}
