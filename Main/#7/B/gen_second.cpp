#include <bits/stdc++.h>
using namespace std;
bool rdb(double ratio)
{
	int randint=rand();
	if(ratio<1e-10) return false;
	if(ratio>(double)1-(1e-10)) return true;
	double randreal=1.0*randint/RAND_MAX;
	return (randreal<=ratio);
}
int rdi(int x)
{
	int c=0;
	for(int i=1;i<=x;i++)
		c*=10,c+=rand()%10;
	return c+1;
}
double rdf()
{
	return 1.0*rand()/RAND_MAX;
}
void gen(int tp,int n1,int n2,int km)
{
	int n=n1+rdi(n2);
	int k=0;
	switch(km)
	{
		case 1:
		{
			k=n-1;
			break;
		}
		case 2:
		{
			k=0;
			break;
		}
		case 3:
		{
			k=rdi(9)%(n/10);
			break;
		}
		default:
		{
			k=rdi(9)%n;
			break;
		}
	}
	cout<<n<<' '<<k<<endl;
	switch(tp)
	{
		case 1:
		{
			for(int i=1;i<=n;i++)
				cout<<'0';
			break;
		}
		case 2:
		{
			for(int i=1;i<=n;i++)
				cout<<'1';
			break;
		}
		default:
		{
			double ratio=rdf();
			for(int i=1;i<=n;i++)
			{
				if(rdb(ratio)) cout<<'0';
				else cout<<'1';
			}
			break;
		}
	}
	cout<<endl;
}
int main()
{
	srand(time(0));
	string tc;
	int t=100,n1,n2,tp1,tp2;
	while(cin>>tc>>n1>>n2>>tp1>>tp2)
	{
		tc+=".in";
		freopen(tc.c_str(),"w",stdout);
		cout<<t<<endl;
		for(int i=1;i<=t;i++)
			gen(tp1,n1,n2,tp2);
	}
	return 0;
}
