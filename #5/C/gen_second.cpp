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
const int N=1000+12;
int a[N];
void gen(int tp,int n)
{
	if(n==-1) n=900+rdi(2);
	cout<<n<<endl;
	switch(tp)
	{
		case 1:
		{
			for(int i=2;i<=n;i++)
			{
				for(int j=1;j<=i-1;j++)
					cout<<'<';
				cout<<endl;
			}
			break;
		}
		case 2:
		{
			for(int i=2;i<=n;i++)
			{
				for(int j=1;j<=i-1;j++)
					cout<<'>';
				cout<<endl;
			}
			break;
		}
		case 3:
		{
			for(int i=1;i<=n;i++)
				a[i]=i;
			shuffle(a+1,a+n+1,default_random_engine(rdi(9)));
			for(int i=2;i<=n;i++)
			{
				for(int j=1;j<=i-1;j++)
				{
					if(a[i]>a[j]) cout<<'>';
					else cout<<'<';
				}
				cout<<endl;
			}
			break;
		}
		default:
		{
			double ratio=rdf();
			for(int i=2;i<=n;i++)
			{
				for(int j=1;j<=i-1;j++)
				{
					if(rdb(ratio)) cout<<'>';
					else cout<<'<';
				}
				cout<<endl;
			}
			break;
		}
	}
}
int main()
{
	srand(time(0));
	string tc;
	int n,t,tp1,tp2;
	while(cin>>tc>>n>>t>>tp1>>tp2)
	{
		tc+=".in";
		freopen(tc.c_str(),"w",stdout);
		cout<<t<<endl;
		gen(tp1,n);
		gen(tp2,n);
		for(int i=3;i<=t;i++)
			gen(min(rand()%10,3),n);
	}
	return 0;
}
